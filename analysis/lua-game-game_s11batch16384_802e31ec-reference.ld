/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802e31ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8030F78C = 0x8030f78c;
fn_8030F7FC = 0x8030f7fc;
SECTIONS {
  .text.w3d_auto_802e31ec 0x802e31ec : { *(.text.w3d_auto_802e31ec) }
  .sdata 0x804abd18 (NOLOAD) : {
    . = 0x0; lbl_804ABD18 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
