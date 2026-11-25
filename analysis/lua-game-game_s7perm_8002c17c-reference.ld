/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002c17c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002BC14 = 0x8002bc14;
lbl_80372644 = 0x80372644;
lbl_80372648 = 0x80372648;
SECTIONS {
  .text.w3d_auto_8002c17c 0x8002c17c : { *(.text.w3d_auto_8002c17c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
