/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_pool_find_80171be4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80185b0c = 0x80185b0c;
fn_80190458 = 0x80190458;
lbl_804a89d8 = 0x804a89d8;
SECTIONS {
  .text.s9_pool_find_80171be4 0x80171be4 : { *(.text.s9_pool_find_80171be4) }
  .text.s9_pool_release_80174798 0x80174798 : { *(.text.s9_pool_release_80174798) }
  .text.s9_pool_find_80174884 0x80174884 : { *(.text.s9_pool_find_80174884) }
  .text.s9_pool_find_8017f8c4 0x8017f8c4 : { *(.text.s9_pool_find_8017f8c4) }
  .text.s9_pool_release_80182b20 0x80182b20 : { *(.text.s9_pool_release_80182b20) }
  .text.s9_pool_release_80184ae8 0x80184ae8 : { *(.text.s9_pool_release_80184ae8) }
  .text.s9_pool_find_80184d68 0x80184d68 : { *(.text.s9_pool_find_80184d68) }
  .text.s9_pool_release_80188440 0x80188440 : { *(.text.s9_pool_release_80188440) }
  .text.s9_pool_find_801886c0 0x801886c0 : { *(.text.s9_pool_find_801886c0) }
  .text.s9_pool_release_8018b0ac 0x8018b0ac : { *(.text.s9_pool_release_8018b0ac) }
  .sdata 0x804ab588 (NOLOAD) : {
    . = 0x0; lbl_804ab588 = .;
    . = 0x4; lbl_804ab58c = .;
    . = 0x8; lbl_804ab590 = .;
    . = 0xc; lbl_804ab594 = .;
    . = 0x84; lbl_804ab60c = .;
    . = 0x88; lbl_804ab610 = .;
    . = 0xb8; lbl_804ab640 = .;
    . = 0xbc; lbl_804ab644 = .;
    . = 0xd0; lbl_804ab658 = .;
    . = 0xd4; lbl_804ab65c = .;
    . = 0xdc; lbl_804ab664 = .;
    . = 0xe0; lbl_804ab668 = .;
    . = 0xf8; lbl_804ab680 = .;
    . = 0xfc; lbl_804ab684 = .;
    . = 0x104; lbl_804ab68c = .;
    . = 0x108; lbl_804ab690 = .;
    . = 0x6314; lbl_804b189c = .;
    . = 0x631c; lbl_804b18a4 = .;
    . = 0x632c; lbl_804b18b4 = .;
    . = 0x6330; lbl_804b18b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
