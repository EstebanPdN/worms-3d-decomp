/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_800d5180)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_80388d4c = 0x80388d4c;
lbl_80388d60 = 0x80388d60;
SECTIONS {
  .text.s8_bound_800d5180 0x800d5180 : { *(.text.s8_bound_800d5180) }
  .sdata 0x804aae4c (NOLOAD) : {
    . = 0x0; lbl_804aae4c = .;
    . = 0x3ba0; lbl_804ae9ec = .;
    . = 0x3ba4; lbl_804ae9f0 = .;
    . = 0x3ba8; lbl_804ae9f4 = .;
    . = 0x3bac; lbl_804ae9f8 = .;
    . = 0x3bb0; lbl_804ae9fc = .;
    . = 0x3bb4; lbl_804aea00 = .;
    . = 0x3bb8; lbl_804aea04 = .;
    . = 0x3bbc; lbl_804aea08 = .;
    . = 0x3bc0; lbl_804aea0c = .;
    . = 0x3bc4; lbl_804aea10 = .;
    . = 0x3bcc; lbl_804aea18 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
