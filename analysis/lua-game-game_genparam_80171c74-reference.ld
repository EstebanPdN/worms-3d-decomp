/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pool_next_80171c74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80185b0c = 0x80185b0c;
SECTIONS {
  .text.w3d_pool_next_80171c74 0x80171c74 : { *(.text.w3d_pool_next_80171c74) }
  .text.w3d_pool_next_80174914 0x80174914 : { *(.text.w3d_pool_next_80174914) }
  .text.w3d_pool_next_80184df8 0x80184df8 : { *(.text.w3d_pool_next_80184df8) }
  .text.w3d_pool_next_80188750 0x80188750 : { *(.text.w3d_pool_next_80188750) }
  .sdata 0x804ab588 (NOLOAD) : {
    . = 0x0; lbl_804ab588 = .;
    . = 0x4; lbl_804ab58c = .;
    . = 0xd0; lbl_804ab658 = .;
    . = 0xd4; lbl_804ab65c = .;
    . = 0xf8; lbl_804ab680 = .;
    . = 0xfc; lbl_804ab684 = .;
    . = 0x6314; lbl_804b189c = .;
    . = 0x631c; lbl_804b18a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
