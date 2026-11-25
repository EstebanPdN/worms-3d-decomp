/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_arena_vectors_sinit_80092ab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802097ec = 0x802097ec;
lbl_8037e888 = 0x8037e888;
lbl_8037e894 = 0x8037e894;
lbl_8037e898 = 0x8037e898;
lbl_8037e89c = 0x8037e89c;
lbl_8037e8a0 = 0x8037e8a0;
lbl_8037e8a4 = 0x8037e8a4;
lbl_8037e8a8 = 0x8037e8a8;
lbl_8037e8ac = 0x8037e8ac;
lbl_80431e88 = 0x80431e88;
lbl_80431e94 = 0x80431e94;
lbl_804336a0 = 0x804336a0;
lbl_804336ac = 0x804336ac;
lbl_804336b8 = 0x804336b8;
lbl_804336c4 = 0x804336c4;
lbl_804336d0 = 0x804336d0;
lbl_804336dc = 0x804336dc;
lbl_804336e8 = 0x804336e8;
lbl_804336f4 = 0x804336f4;
lbl_80433700 = 0x80433700;
lbl_8043370c = 0x8043370c;
lbl_80433718 = 0x80433718;
lbl_80433724 = 0x80433724;
lbl_80433730 = 0x80433730;
lbl_8043373c = 0x8043373c;
lbl_80433748 = 0x80433748;
lbl_80433754 = 0x80433754;
SECTIONS {
  .text.w3d_cc20a_arena_vectors_sinit_80092ab8 0x80092ab8 : { *(.text.w3d_cc20a_arena_vectors_sinit_80092ab8) }
  .sdata 0x804aab54 (NOLOAD) : {
    . = 0x0; lbl_804aab54 = .;
    . = 0x326c; lbl_804addc0 = .;
    . = 0x3270; lbl_804addc4 = .;
    . = 0x3274; lbl_804addc8 = .;
    . = 0x3278; lbl_804addcc = .;
    . = 0x327c; lbl_804addd0 = .;
    . = 0x3280; lbl_804addd4 = .;
    . = 0x3284; lbl_804addd8 = .;
    . = 0x3288; lbl_804adddc = .;
    . = 0x328c; lbl_804adde0 = .;
    . = 0x3290; lbl_804adde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
