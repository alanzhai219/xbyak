#include <stdio.h>
#include <string.h>
#include <xbyak/xbyak.h>
#include <xbyak/xbyak_util.h>
#include <cybozu/test.hpp>

#ifndef XBYAK64
	#error "only 64-bit mode"
#endif

using namespace Xbyak;

CYBOZU_TEST_AUTO(reg64)
{
	struct Code : Xbyak::CodeGenerator {
		Code()
		{
			adc(r30, rax); adc(r30, rcx); adc(r30, rdx); adc(r30, rbx); adc(r30, rsp); adc(r30, rbp); adc(r30, rsi); adc(r30, rdi);
			adc(r30, r8); adc(r30, r9); adc(r30, r10); adc(r30, r11); adc(r30, r12); adc(r30, r13); adc(r30, r14); adc(r30, r15);
			adc(r30, r16); adc(r30, r17); adc(r30, r18); adc(r30, r19); adc(r30, r20); adc(r30, r21); adc(r30, r22); adc(r30, r23);
			adc(r30, r24); adc(r30, r25); adc(r30, r26); adc(r30, r27); adc(r30, r28); adc(r30, r29); adc(r30, r30); adc(r30, r31);
			adc(rax, r30); adc(rcx, r30); adc(rdx, r30); adc(rbx, r30); adc(rsp, r30); adc(rbp, r30); adc(rsi, r30); adc(rdi, r30);
			adc(r8, r30); adc(r9, r30); adc(r10, r30); adc(r11, r30); adc(r12, r30); adc(r13, r30); adc(r14, r30); adc(r15, r30);
			adc(r16, r30); adc(r17, r30); adc(r18, r30); adc(r19, r30); adc(r20, r30); adc(r21, r30); adc(r22, r30); adc(r23, r30);
			adc(r24, r30); adc(r25, r30); adc(r26, r30); adc(r27, r30); adc(r28, r30); adc(r29, r30); adc(r30, r30); adc(r31, r30);
		}
	}  c;
	const uint8_t tbl[] = {
		0xd5, 0x19, 0x11, 0xc6, 0xd5, 0x19, 0x11, 0xce, 0xd5, 0x19, 0x11, 0xd6, 0xd5, 0x19, 0x11, 0xde,
		0xd5, 0x19, 0x11, 0xe6, 0xd5, 0x19, 0x11, 0xee, 0xd5, 0x19, 0x11, 0xf6, 0xd5, 0x19, 0x11, 0xfe,
		0xd5, 0x1d, 0x11, 0xc6, 0xd5, 0x1d, 0x11, 0xce, 0xd5, 0x1d, 0x11, 0xd6, 0xd5, 0x1d, 0x11, 0xde,
		0xd5, 0x1d, 0x11, 0xe6, 0xd5, 0x1d, 0x11, 0xee, 0xd5, 0x1d, 0x11, 0xf6, 0xd5, 0x1d, 0x11, 0xfe,
		0xd5, 0x59, 0x11, 0xc6, 0xd5, 0x59, 0x11, 0xce, 0xd5, 0x59, 0x11, 0xd6, 0xd5, 0x59, 0x11, 0xde,
		0xd5, 0x59, 0x11, 0xe6, 0xd5, 0x59, 0x11, 0xee, 0xd5, 0x59, 0x11, 0xf6, 0xd5, 0x59, 0x11, 0xfe,
		0xd5, 0x5d, 0x11, 0xc6, 0xd5, 0x5d, 0x11, 0xce, 0xd5, 0x5d, 0x11, 0xd6, 0xd5, 0x5d, 0x11, 0xde,
		0xd5, 0x5d, 0x11, 0xe6, 0xd5, 0x5d, 0x11, 0xee, 0xd5, 0x5d, 0x11, 0xf6, 0xd5, 0x5d, 0x11, 0xfe,
		0xd5, 0x4c, 0x11, 0xf0, 0xd5, 0x4c, 0x11, 0xf1, 0xd5, 0x4c, 0x11, 0xf2, 0xd5, 0x4c, 0x11, 0xf3,
		0xd5, 0x4c, 0x11, 0xf4, 0xd5, 0x4c, 0x11, 0xf5, 0xd5, 0x4c, 0x11, 0xf6, 0xd5, 0x4c, 0x11, 0xf7,
		0xd5, 0x4d, 0x11, 0xf0, 0xd5, 0x4d, 0x11, 0xf1, 0xd5, 0x4d, 0x11, 0xf2, 0xd5, 0x4d, 0x11, 0xf3,
		0xd5, 0x4d, 0x11, 0xf4, 0xd5, 0x4d, 0x11, 0xf5, 0xd5, 0x4d, 0x11, 0xf6, 0xd5, 0x4d, 0x11, 0xf7,
		0xd5, 0x5c, 0x11, 0xf0, 0xd5, 0x5c, 0x11, 0xf1, 0xd5, 0x5c, 0x11, 0xf2, 0xd5, 0x5c, 0x11, 0xf3,
		0xd5, 0x5c, 0x11, 0xf4, 0xd5, 0x5c, 0x11, 0xf5, 0xd5, 0x5c, 0x11, 0xf6, 0xd5, 0x5c, 0x11, 0xf7,
		0xd5, 0x5d, 0x11, 0xf0, 0xd5, 0x5d, 0x11, 0xf1, 0xd5, 0x5d, 0x11, 0xf2, 0xd5, 0x5d, 0x11, 0xf3,
		0xd5, 0x5d, 0x11, 0xf4, 0xd5, 0x5d, 0x11, 0xf5, 0xd5, 0x5d, 0x11, 0xf6, 0xd5, 0x5d, 0x11, 0xf7,
	};
	const size_t n = sizeof(tbl);
	CYBOZU_TEST_EQUAL(c.getSize(), n);
	CYBOZU_TEST_EQUAL_ARRAY(c.getCode(), tbl, n);
}

CYBOZU_TEST_AUTO(reg32)
{
	struct Code : Xbyak::CodeGenerator {
		Code()
		{
			adc(r30d, eax); adc(r30d, ecx); adc(r30d, edx); adc(r30d, ebx); adc(r30d, esp); adc(r30d, ebp); adc(r30d, esi); adc(r30d, edi);
			adc(r30d, r8d); adc(r30d, r9d); adc(r30d, r10d); adc(r30d, r11d); adc(r30d, r12d); adc(r30d, r13d); adc(r30d, r14d); adc(r30d, r15d);
			adc(r30d, r16d); adc(r30d, r17d); adc(r30d, r18d); adc(r30d, r19d); adc(r30d, r20d); adc(r30d, r21d); adc(r30d, r22d); adc(r30d, r23d);
			adc(r30d, r24d); adc(r30d, r25d); adc(r30d, r26d); adc(r30d, r27d); adc(r30d, r28d); adc(r30d, r29d); adc(r30d, r30d); adc(r30d, r31d);
			adc(eax, r29d); adc(ecx, r29d); adc(edx, r29d); adc(ebx, r29d); adc(esp, r29d); adc(ebp, r29d); adc(esi, r29d); adc(edi, r29d);
			adc(r8d, r29d); adc(r9d, r29d); adc(r10d, r29d); adc(r11d, r29d); adc(r12d, r29d); adc(r13d, r29d); adc(r14d, r29d); adc(r15d, r29d);
			adc(r16d, r29d); adc(r17d, r29d); adc(r18d, r29d); adc(r19d, r29d); adc(r20d, r29d); adc(r21d, r29d); adc(r22d, r29d); adc(r23d, r29d);
			adc(r24d, r29d); adc(r25d, r29d); adc(r26d, r29d); adc(r27d, r29d); adc(r28d, r29d); adc(r29d, r29d); adc(r30d, r29d); adc(r31d, r29d);
		}
	}  c;
	const uint8_t tbl[] = {
		0xd5, 0x11, 0x11, 0xc6, 0xd5, 0x11, 0x11, 0xce, 0xd5, 0x11, 0x11, 0xd6, 0xd5, 0x11, 0x11, 0xde,
		0xd5, 0x11, 0x11, 0xe6, 0xd5, 0x11, 0x11, 0xee, 0xd5, 0x11, 0x11, 0xf6, 0xd5, 0x11, 0x11, 0xfe,
		0xd5, 0x15, 0x11, 0xc6, 0xd5, 0x15, 0x11, 0xce, 0xd5, 0x15, 0x11, 0xd6, 0xd5, 0x15, 0x11, 0xde,
		0xd5, 0x15, 0x11, 0xe6, 0xd5, 0x15, 0x11, 0xee, 0xd5, 0x15, 0x11, 0xf6, 0xd5, 0x15, 0x11, 0xfe,
		0xd5, 0x51, 0x11, 0xc6, 0xd5, 0x51, 0x11, 0xce, 0xd5, 0x51, 0x11, 0xd6, 0xd5, 0x51, 0x11, 0xde,
		0xd5, 0x51, 0x11, 0xe6, 0xd5, 0x51, 0x11, 0xee, 0xd5, 0x51, 0x11, 0xf6, 0xd5, 0x51, 0x11, 0xfe,
		0xd5, 0x55, 0x11, 0xc6, 0xd5, 0x55, 0x11, 0xce, 0xd5, 0x55, 0x11, 0xd6, 0xd5, 0x55, 0x11, 0xde,
		0xd5, 0x55, 0x11, 0xe6, 0xd5, 0x55, 0x11, 0xee, 0xd5, 0x55, 0x11, 0xf6, 0xd5, 0x55, 0x11, 0xfe,
		0xd5, 0x44, 0x11, 0xe8, 0xd5, 0x44, 0x11, 0xe9, 0xd5, 0x44, 0x11, 0xea, 0xd5, 0x44, 0x11, 0xeb,
		0xd5, 0x44, 0x11, 0xec, 0xd5, 0x44, 0x11, 0xed, 0xd5, 0x44, 0x11, 0xee, 0xd5, 0x44, 0x11, 0xef,
		0xd5, 0x45, 0x11, 0xe8, 0xd5, 0x45, 0x11, 0xe9, 0xd5, 0x45, 0x11, 0xea, 0xd5, 0x45, 0x11, 0xeb,
		0xd5, 0x45, 0x11, 0xec, 0xd5, 0x45, 0x11, 0xed, 0xd5, 0x45, 0x11, 0xee, 0xd5, 0x45, 0x11, 0xef,
		0xd5, 0x54, 0x11, 0xe8, 0xd5, 0x54, 0x11, 0xe9, 0xd5, 0x54, 0x11, 0xea, 0xd5, 0x54, 0x11, 0xeb,
		0xd5, 0x54, 0x11, 0xec, 0xd5, 0x54, 0x11, 0xed, 0xd5, 0x54, 0x11, 0xee, 0xd5, 0x54, 0x11, 0xef,
		0xd5, 0x55, 0x11, 0xe8, 0xd5, 0x55, 0x11, 0xe9, 0xd5, 0x55, 0x11, 0xea, 0xd5, 0x55, 0x11, 0xeb,
		0xd5, 0x55, 0x11, 0xec, 0xd5, 0x55, 0x11, 0xed, 0xd5, 0x55, 0x11, 0xee, 0xd5, 0x55, 0x11, 0xef,
	};
	const size_t n = sizeof(tbl);
	CYBOZU_TEST_EQUAL(c.getSize(), n);
	CYBOZU_TEST_EQUAL_ARRAY(c.getCode(), tbl, n);
}

CYBOZU_TEST_AUTO(reg16)
{
	struct Code : Xbyak::CodeGenerator {
		Code()
		{
			adc(r30w, ax); adc(r30w, cx); adc(r30w, dx); adc(r30w, bx); adc(r30w, sp); adc(r30w, bp); adc(r30w, si); adc(r30w, di);
			adc(r30w, r8w); adc(r30w, r9w); adc(r30w, r10w); adc(r30w, r11w); adc(r30w, r12w); adc(r30w, r13w); adc(r30w, r14w); adc(r30w, r15w);
			adc(r30w, r16w); adc(r30w, r17w); adc(r30w, r18w); adc(r30w, r19w); adc(r30w, r20w); adc(r30w, r21w); adc(r30w, r22w); adc(r30w, r23w);
			adc(r30w, r24w); adc(r30w, r25w); adc(r30w, r26w); adc(r30w, r27w); adc(r30w, r28w); adc(r30w, r29w); adc(r30w, r30w); adc(r30w, r31w);
			adc(ax, r29w); adc(cx, r29w); adc(dx, r29w); adc(bx, r29w); adc(sp, r29w); adc(bp, r29w); adc(si, r29w); adc(di, r29w);
			adc(r8w, r29w); adc(r9w, r29w); adc(r10w, r29w); adc(r11w, r29w); adc(r12w, r29w); adc(r13w, r29w); adc(r14w, r29w); adc(r15w, r29w);
			adc(r16w, r29w); adc(r17w, r29w); adc(r18w, r29w); adc(r19w, r29w); adc(r20w, r29w); adc(r21w, r29w); adc(r22w, r29w); adc(r23w, r29w);
			adc(r24w, r29w); adc(r25w, r29w); adc(r26w, r29w); adc(r27w, r29w); adc(r28w, r29w); adc(r29w, r29w); adc(r30w, r29w); adc(r31w, r29w);
		}
	}  c;
	const uint8_t tbl[] = {
		0x66, 0xd5, 0x11, 0x11, 0xc6, 0x66, 0xd5, 0x11, 0x11, 0xce, 0x66, 0xd5, 0x11, 0x11, 0xd6, 0x66,
		0xd5, 0x11, 0x11, 0xde, 0x66, 0xd5, 0x11, 0x11, 0xe6, 0x66, 0xd5, 0x11, 0x11, 0xee, 0x66, 0xd5,
		0x11, 0x11, 0xf6, 0x66, 0xd5, 0x11, 0x11, 0xfe, 0x66, 0xd5, 0x15, 0x11, 0xc6, 0x66, 0xd5, 0x15,
		0x11, 0xce, 0x66, 0xd5, 0x15, 0x11, 0xd6, 0x66, 0xd5, 0x15, 0x11, 0xde, 0x66, 0xd5, 0x15, 0x11,
		0xe6, 0x66, 0xd5, 0x15, 0x11, 0xee, 0x66, 0xd5, 0x15, 0x11, 0xf6, 0x66, 0xd5, 0x15, 0x11, 0xfe,
		0x66, 0xd5, 0x51, 0x11, 0xc6, 0x66, 0xd5, 0x51, 0x11, 0xce, 0x66, 0xd5, 0x51, 0x11, 0xd6, 0x66,
		0xd5, 0x51, 0x11, 0xde, 0x66, 0xd5, 0x51, 0x11, 0xe6, 0x66, 0xd5, 0x51, 0x11, 0xee, 0x66, 0xd5,
		0x51, 0x11, 0xf6, 0x66, 0xd5, 0x51, 0x11, 0xfe, 0x66, 0xd5, 0x55, 0x11, 0xc6, 0x66, 0xd5, 0x55,
		0x11, 0xce, 0x66, 0xd5, 0x55, 0x11, 0xd6, 0x66, 0xd5, 0x55, 0x11, 0xde, 0x66, 0xd5, 0x55, 0x11,
		0xe6, 0x66, 0xd5, 0x55, 0x11, 0xee, 0x66, 0xd5, 0x55, 0x11, 0xf6, 0x66, 0xd5, 0x55, 0x11, 0xfe,
		0x66, 0xd5, 0x44, 0x11, 0xe8, 0x66, 0xd5, 0x44, 0x11, 0xe9, 0x66, 0xd5, 0x44, 0x11, 0xea, 0x66,
		0xd5, 0x44, 0x11, 0xeb, 0x66, 0xd5, 0x44, 0x11, 0xec, 0x66, 0xd5, 0x44, 0x11, 0xed, 0x66, 0xd5,
		0x44, 0x11, 0xee, 0x66, 0xd5, 0x44, 0x11, 0xef, 0x66, 0xd5, 0x45, 0x11, 0xe8, 0x66, 0xd5, 0x45,
		0x11, 0xe9, 0x66, 0xd5, 0x45, 0x11, 0xea, 0x66, 0xd5, 0x45, 0x11, 0xeb, 0x66, 0xd5, 0x45, 0x11,
		0xec, 0x66, 0xd5, 0x45, 0x11, 0xed, 0x66, 0xd5, 0x45, 0x11, 0xee, 0x66, 0xd5, 0x45, 0x11, 0xef,
		0x66, 0xd5, 0x54, 0x11, 0xe8, 0x66, 0xd5, 0x54, 0x11, 0xe9, 0x66, 0xd5, 0x54, 0x11, 0xea, 0x66,
		0xd5, 0x54, 0x11, 0xeb, 0x66, 0xd5, 0x54, 0x11, 0xec, 0x66, 0xd5, 0x54, 0x11, 0xed, 0x66, 0xd5,
		0x54, 0x11, 0xee, 0x66, 0xd5, 0x54, 0x11, 0xef, 0x66, 0xd5, 0x55, 0x11, 0xe8, 0x66, 0xd5, 0x55,
		0x11, 0xe9, 0x66, 0xd5, 0x55, 0x11, 0xea, 0x66, 0xd5, 0x55, 0x11, 0xeb, 0x66, 0xd5, 0x55, 0x11,
		0xec, 0x66, 0xd5, 0x55, 0x11, 0xed, 0x66, 0xd5, 0x55, 0x11, 0xee, 0x66, 0xd5, 0x55, 0x11, 0xef,
	};
	const size_t n = sizeof(tbl);
	CYBOZU_TEST_EQUAL(c.getSize(), n);
	CYBOZU_TEST_EQUAL_ARRAY(c.getCode(), tbl, n);
}

CYBOZU_TEST_AUTO(reg8)
{
	struct Code : Xbyak::CodeGenerator {
		Code()
		{
			adc(r17b, al); adc(r17b, cl); adc(r17b, dl); adc(r17b, bl); adc(r17b, spl); adc(r17b, bpl); adc(r17b, sil); adc(r17b, dil);
			adc(r17b, r8b); adc(r17b, r9b); adc(r17b, r10b); adc(r17b, r11b); adc(r17b, r12b); adc(r17b, r13b); adc(r17b, r14b); adc(r17b, r15b);
			adc(r17b, r16b); adc(r17b, r17b); adc(r17b, r18b); adc(r17b, r19b); adc(r17b, r20b); adc(r17b, r21b); adc(r17b, r22b); adc(r17b, r23b);
			adc(r17b, r24b); adc(r17b, r25b); adc(r17b, r26b); adc(r17b, r27b); adc(r17b, r28b); adc(r17b, r29b); adc(r17b, r30b); adc(r17b, r31b);
			adc(al, r20b); adc(cl, r20b); adc(dl, r20b); adc(bl, r20b); adc(spl, r20b); adc(bpl, r20b); adc(sil, r20b); adc(dil, r20b);
			adc(r8b, r20b); adc(r9b, r20b); adc(r10b, r20b); adc(r11b, r20b); adc(r12b, r20b); adc(r13b, r20b); adc(r14b, r20b); adc(r15b, r20b);
			adc(r16b, r20b); adc(r17b, r20b); adc(r18b, r20b); adc(r19b, r20b); adc(r20b, r20b); adc(r21b, r20b); adc(r22b, r20b); adc(r23b, r20b);
			adc(r24b, r20b); adc(r25b, r20b); adc(r26b, r20b); adc(r27b, r20b); adc(r28b, r20b); adc(r29b, r20b); adc(r30b, r20b); adc(r31b, r20b);
		}
	}  c;
	const uint8_t tbl[] = {
		0xd5, 0x10, 0x10, 0xc1, 0xd5, 0x10, 0x10, 0xc9, 0xd5, 0x10, 0x10, 0xd1, 0xd5, 0x10, 0x10, 0xd9,
		0xd5, 0x10, 0x10, 0xe1, 0xd5, 0x10, 0x10, 0xe9, 0xd5, 0x10, 0x10, 0xf1, 0xd5, 0x10, 0x10, 0xf9,
		0xd5, 0x14, 0x10, 0xc1, 0xd5, 0x14, 0x10, 0xc9, 0xd5, 0x14, 0x10, 0xd1, 0xd5, 0x14, 0x10, 0xd9,
		0xd5, 0x14, 0x10, 0xe1, 0xd5, 0x14, 0x10, 0xe9, 0xd5, 0x14, 0x10, 0xf1, 0xd5, 0x14, 0x10, 0xf9,
		0xd5, 0x50, 0x10, 0xc1, 0xd5, 0x50, 0x10, 0xc9, 0xd5, 0x50, 0x10, 0xd1, 0xd5, 0x50, 0x10, 0xd9,
		0xd5, 0x50, 0x10, 0xe1, 0xd5, 0x50, 0x10, 0xe9, 0xd5, 0x50, 0x10, 0xf1, 0xd5, 0x50, 0x10, 0xf9,
		0xd5, 0x54, 0x10, 0xc1, 0xd5, 0x54, 0x10, 0xc9, 0xd5, 0x54, 0x10, 0xd1, 0xd5, 0x54, 0x10, 0xd9,
		0xd5, 0x54, 0x10, 0xe1, 0xd5, 0x54, 0x10, 0xe9, 0xd5, 0x54, 0x10, 0xf1, 0xd5, 0x54, 0x10, 0xf9,
		0xd5, 0x40, 0x10, 0xe0, 0xd5, 0x40, 0x10, 0xe1, 0xd5, 0x40, 0x10, 0xe2, 0xd5, 0x40, 0x10, 0xe3,
		0xd5, 0x40, 0x10, 0xe4, 0xd5, 0x40, 0x10, 0xe5, 0xd5, 0x40, 0x10, 0xe6, 0xd5, 0x40, 0x10, 0xe7,
		0xd5, 0x41, 0x10, 0xe0, 0xd5, 0x41, 0x10, 0xe1, 0xd5, 0x41, 0x10, 0xe2, 0xd5, 0x41, 0x10, 0xe3,
		0xd5, 0x41, 0x10, 0xe4, 0xd5, 0x41, 0x10, 0xe5, 0xd5, 0x41, 0x10, 0xe6, 0xd5, 0x41, 0x10, 0xe7,
		0xd5, 0x50, 0x10, 0xe0, 0xd5, 0x50, 0x10, 0xe1, 0xd5, 0x50, 0x10, 0xe2, 0xd5, 0x50, 0x10, 0xe3,
		0xd5, 0x50, 0x10, 0xe4, 0xd5, 0x50, 0x10, 0xe5, 0xd5, 0x50, 0x10, 0xe6, 0xd5, 0x50, 0x10, 0xe7,
		0xd5, 0x51, 0x10, 0xe0, 0xd5, 0x51, 0x10, 0xe1, 0xd5, 0x51, 0x10, 0xe2, 0xd5, 0x51, 0x10, 0xe3,
		0xd5, 0x51, 0x10, 0xe4, 0xd5, 0x51, 0x10, 0xe5, 0xd5, 0x51, 0x10, 0xe6, 0xd5, 0x51, 0x10, 0xe7,
	};
	const size_t n = sizeof(tbl);
	CYBOZU_TEST_EQUAL(c.getSize(), n);
	CYBOZU_TEST_EQUAL_ARRAY(c.getCode(), tbl, n);
}

CYBOZU_TEST_AUTO(rm)
{
	struct Code : Xbyak::CodeGenerator {
		Code()
		{
			adc(r16, ptr [r17+0x40]);
			adc(ptr [r17+0x40], r16);
			adc(r16d, ptr [r17+0x40]);
			adc(ptr [r17+0x40], r16d);
			adc(r16w, ptr [r17+0x40]);
			adc(ptr [r17+0x40], r16w);
			adc(r16b, ptr [r17+0x40]);
			adc(ptr [r17+0x40], r16b);
			adc(r16, ptr [r18*4+0x40]);
			adc(ptr [r18*4+0x40], r16);
			adc(r16d, ptr [r18*4+0x40]);
			adc(ptr [r18*4+0x40], r16d);
			adc(r16w, ptr [r18*4+0x40]);
			adc(ptr [r18*4+0x40], r16w);
			adc(r16b, ptr [r18*4+0x40]);
			adc(ptr [r18*4+0x40], r16b);
			adc(r16, ptr [r17+r18*4+0x40]);
			adc(ptr [r17+r18*4+0x40], r16);
			adc(r16d, ptr [r17+r18*4+0x40]);
			adc(ptr [r17+r18*4+0x40], r16d);
			adc(r16w, ptr [r17+r18*4+0x40]);
			adc(ptr [r17+r18*4+0x40], r16w);
			adc(r16b, ptr [r17+r18*4+0x40]);
			adc(ptr [r17+r18*4+0x40], r16b);
		}
	}  c;
	const uint8_t tbl[] = {
		0xd5, 0x58, 0x13, 0x41, 0x40, 0xd5, 0x58, 0x11, 0x41, 0x40, 0xd5, 0x50, 0x13, 0x41, 0x40, 0xd5,
		0x50, 0x11, 0x41, 0x40, 0x66, 0xd5, 0x50, 0x13, 0x41, 0x40, 0x66, 0xd5, 0x50, 0x11, 0x41, 0x40,
		0xd5, 0x50, 0x12, 0x41, 0x40, 0xd5, 0x50, 0x10, 0x41, 0x40, 0xd5, 0x68, 0x13, 0x04, 0x95, 0x40,
		0x00, 0x00, 0x00, 0xd5, 0x68, 0x11, 0x04, 0x95, 0x40, 0x00, 0x00, 0x00, 0xd5, 0x60, 0x13, 0x04,
		0x95, 0x40, 0x00, 0x00, 0x00, 0xd5, 0x60, 0x11, 0x04, 0x95, 0x40, 0x00, 0x00, 0x00, 0x66, 0xd5,
		0x60, 0x13, 0x04, 0x95, 0x40, 0x00, 0x00, 0x00, 0x66, 0xd5, 0x60, 0x11, 0x04, 0x95, 0x40, 0x00,
		0x00, 0x00, 0xd5, 0x60, 0x12, 0x04, 0x95, 0x40, 0x00, 0x00, 0x00, 0xd5, 0x60, 0x10, 0x04, 0x95,
		0x40, 0x00, 0x00, 0x00, 0xd5, 0x78, 0x13, 0x44, 0x91, 0x40, 0xd5, 0x78, 0x11, 0x44, 0x91, 0x40,
		0xd5, 0x70, 0x13, 0x44, 0x91, 0x40, 0xd5, 0x70, 0x11, 0x44, 0x91, 0x40, 0x66, 0xd5, 0x70, 0x13,
		0x44, 0x91, 0x40, 0x66, 0xd5, 0x70, 0x11, 0x44, 0x91, 0x40, 0xd5, 0x70, 0x12, 0x44, 0x91, 0x40,
		0xd5, 0x70, 0x10, 0x44, 0x91, 0x40,
	};
	const size_t n = sizeof(tbl);
	CYBOZU_TEST_EQUAL(c.getSize(), n);
	CYBOZU_TEST_EQUAL_ARRAY(c.getCode(), tbl, n);
}
