/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b34_probe_800de75c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0824 = 0x800b0824;
lbl_80389bfc = 0x80389bfc;
lbl_80389c00 = 0x80389c00;
SECTIONS {
  .text.tsonnet_b34_probe_800de75c 0x800de75c : { *(.text.tsonnet_b34_probe_800de75c) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . = 0x44; lbl_804b17a8 = .;
    . = 0x48; lbl_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
