import os
import re
import requests
import requests.adapters

from typing import Tuple

LANGUAGES = {"C99": 0, "C++98": 1, "Pascal": 2, "Text": 58}

COOKIES = {"bojautologin": os.environ.get("BOJ_AUTOLOGIN")}

HEADERS = {
    "Connection": "keep-alive",
    "Cache-Control": "max-age=0",
    "Sec-Ch-Ua": '"Not A(Brand";v="99", "Google Chrome";v="121", "Chromium";v="121"',
    "Sec-Ch-Ua-Mobile": "?0",
    "Sec-Ch-Ua-Platform": '"Windows"',
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36",
    "Origin": "https://www.acmicpc.net",
    "Content-Type": "application/x-www-form-urlencoded",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Sec-Fetch-Site": "same-origin",
    "Sec-Fetch-Mode": "navigate",
    "Sec-Fetch-User": "?1",
    "Sec-Fetch-Dest": "document",
    "Referer": "https://www.acmicpc.net/",
    "Accept-Encoding": "gzip, deflate, br",
    "Accept-Language": "en-US,en;q=0.9,ko-KR;q=0.8,ko;q=0.7",
}


class SubmitFailed(Exception):
    pass


def submit(
    problem_id: int, language: str, code_open: str, source: str
) -> Tuple[bool, requests.Response]:
    try:
        s = requests.Session()
        retries = requests.adapters.Retry(total=5, backoff_factor=0.1)
        s.mount("https://", requests.adapters.HTTPAdapter(max_retries=retries))

        s.headers = HEADERS
        s.verify = True

        for k, v in COOKIES.items():
            s.cookies.set(k, v)

        r = s.get(f"https://www.acmicpc.net/submit/{problem_id}", timeout=10)

        if r.status_code != 200:
            raise SubmitFailed(f"GET failed: {r.status_code}")

        m = re.search('name="csrf_key" value="([0-9a-f]+)"', r.text)

        if m is None or (csrf_key := m.group(1)) is None:
            raise SubmitFailed(f"CSRF token not found")

        s.headers["Content-Type"] = "application/x-www-form-urlencoded"

        data = {
            "problem_id": str(problem_id),
            "language": str(LANGUAGES[language]),
            "code_open": code_open,
            "source": source,
            "csrf_key": csrf_key,
        }

        r = s.post(
            f"https://www.acmicpc.net/submit/{problem_id}",
            data=data,
            timeout=10,
            allow_redirects=False,
        )
    except requests.RequestException:
        raise SubmitFailed(f"Network error")

    return r.status_code == 302, r
