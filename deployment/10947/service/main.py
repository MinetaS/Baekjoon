import BOJ
import time

TIME_FORMAT = "%Y-%m-%d-%H-%M-%S"


def log(message: str):
    print(f"[{time.strftime(TIME_FORMAT, time.localtime())}] {message}", flush=True)


def save_last_submit(last_submit_time, submit_count: int):
    with open("submit_count.dat", "w") as f:
        f.write(f"{time.strftime(TIME_FORMAT, last_submit_time)} {submit_count}")


def read_last_submit():
    with open("submit_count.dat", "r") as f:
        data = f.read().split(" ")
        last_submit_time, submit_count = time.strptime(data[0], TIME_FORMAT), int(
            data[1]
        )

    current_time = time.localtime()

    if not (
        last_submit_time.tm_year == current_time.tm_year
        and last_submit_time.tm_mon == current_time.tm_mon
        and last_submit_time.tm_mday == current_time.tm_mday
    ):
        submit_count = 0

    return last_submit_time, submit_count


if __name__ == "__main__":
    last_submit_time, submit_count = read_last_submit()
    failed_first = True

    try:
        while True:
            # Prepare for the next day
            if time.localtime().tm_hour == 23 and time.localtime().tm_min == 59:
                time.sleep(60)

            if last_submit_time.tm_mday != time.localtime().tm_mday:
                submit_count = 0
                log(f"Submit count reset!!")

            try:
                r = BOJ.submit(10947, "Text", "close", "4 11 19 26 34 41")
            except BOJ.SubmitFailed as e:
                log(f"Submit #{submit_count + 1} - Failed ({e.args[0]})")
                time.sleep(5)
                continue

            if not r[0]:
                log(f"Submit #{submit_count + 1} - Failed ({r[1].status_code})")

                # Adjust submit_count
                if failed_first and r[1].status_code == 200:
                    submit_count += 1
                    failed_first = False
                    log(f"Submit count adjusted: {submit_count + 1}")

                time.sleep(10)
                continue

            failed_first = True
            submit_count += 1
            last_submit_time = time.localtime()
            save_last_submit(last_submit_time := time.localtime(), submit_count)

            log(f"Submit #{submit_count} - Success")

            delay = 10 * (submit_count // 50 + 1)
            time.sleep(delay)

    except KeyboardInterrupt:
        exit()
