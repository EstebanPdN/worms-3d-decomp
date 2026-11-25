/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_pool_acquire_80182a24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80190438 = 0x80190438;
lbl_804a89d8 = 0x804a89d8;
SECTIONS {
  .text.s9_pool_acquire_80182a24 0x80182a24 : { *(.text.s9_pool_acquire_80182a24) }
  .text.s9_pool_acquire_801849ec 0x801849ec : { *(.text.s9_pool_acquire_801849ec) }
  .text.s9_pool_acquire_80188344 0x80188344 : { *(.text.s9_pool_acquire_80188344) }
  .text.s9_pool_acquire_8018afb0 0x8018afb0 : { *(.text.s9_pool_acquire_8018afb0) }
  .sdata 0x804ab634 (NOLOAD) : {
    . = 0x0; lbl_804ab634 = .;
    . = 0xc; lbl_804ab640 = .;
    . = 0x10; lbl_804ab644 = .;
    . = 0x24; lbl_804ab658 = .;
    . = 0x30; lbl_804ab664 = .;
    . = 0x34; lbl_804ab668 = .;
    . = 0x4c; lbl_804ab680 = .;
    . = 0x58; lbl_804ab68c = .;
    . = 0x5c; lbl_804ab690 = .;
    . = 0x627c; lbl_804b18b0 = .;
    . = 0x6280; lbl_804b18b4 = .;
    . = 0x6284; lbl_804b18b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
