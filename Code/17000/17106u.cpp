#include <cstdio>

int main() {
	unsigned int map;

	for (map=0 ; map<(1u<<26) ; map++) {
		bool A1 = (map >> 0) & 0x1u;
		bool A2 = (map >> 1) & 0x1u;
		bool A3 = (map >> 2) & 0x1u;
		bool A4 = (map >> 3) & 0x1u;
		bool A5 = (map >> 4) & 0x1u;
		bool B1 = (map >> 5) & 0x1u;
		bool B2 = (map >> 6) & 0x1u;
		bool B3 = (map >> 7) & 0x1u;
		bool B4 = (map >> 8) & 0x1u;
		bool B5 = (map >> 9) & 0x1u;
		bool C1 = (map >> 10) & 0x1u;
		bool C2 = (map >> 11) & 0x1u;
		bool C3 = (map >> 12) & 0x1u;
		bool C4 = (map >> 13) & 0x1u;
		bool C5 = (map >> 14) & 0x1u;
		bool D1 = (map >> 15) & 0x1u;
		bool D2 = (map >> 16) & 0x1u;
		bool D3 = (map >> 17) & 0x1u;
		bool D4 = (map >> 18) & 0x1u;
		bool D5 = (map >> 19) & 0x1u;
		bool E1 = (map >> 20) & 0x1u;
		bool E2 = (map >> 21) & 0x1u;
		bool E3 = (map >> 22) & 0x1u;
		bool E4 = (map >> 23) & 0x1u;
		bool E5 = (map >> 24) & 0x1u;

		bool LV1 = A1 && A2 && A3 && A4 && A5;
		bool LV2 = B1 && B2 && B3 && B4 && B5;
		bool LV3 = C1 && C2 && C3 && C4 && C5;
		bool LV4 = D1 && D2 && D3 && D4 && D5;
		bool LV5 = E1 && E2 && E3 && E4 && E5;
		bool LH1 = A1 && B1 && C1 && D1 && E1;
		bool LH2 = A2 && B2 && C2 && D2 && E2;
		bool LH3 = A3 && B3 && C3 && D3 && E3;
		bool LH4 = A4 && B4 && C4 && D4 && E4;
		bool LH5 = A5 && B5 && C5 && D5 && E5;
		bool LD1 = A1 && B2 && C3 && D4 && E5;
		bool LD2 = A5 && B4 && C3 && D2 && E1;

		if (A1 ^ !LD2) continue;
		if (A2 ^ !A4) continue;
		if (A3 ^ (LV1 || LH3)) continue;
		if (A4 ^ !A2) continue;
		if (A5 ^ E5) continue;
		if (B1 ^ !(LV2 || LH1)) continue;
		if (B2 ^ ((LV1 || LV2 || LV3 || LV4 || LV5) && (LH1 || LH2 || LH3 || LH4 || LH5) && (LD1 || LD2))) continue;
		// fio

	}
}