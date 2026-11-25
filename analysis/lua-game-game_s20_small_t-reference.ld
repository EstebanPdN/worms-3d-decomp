/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_destruct_counted_80172b64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801858fc = 0x801858fc;
lbl_80412068 = 0x80412068;
SECTIONS {
  .text.w3d_s20_destruct_counted_80172b64 0x80172b64 : { *(.text.w3d_s20_destruct_counted_80172b64) }
  .sdata 0x804ab580 (NOLOAD) : {
    . = 0x0; lbl_804ab580 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
