/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_singleton_create_801655fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18w3d_class_80165924 = 0x80165924;
__nw__18w3d_class_80165924Ui = 0x801fe1d8;
fn_8016568c = 0x8016568c;
fn_801656b4 = 0x801656b4;
fn_8020b648 = 0x8020b648;
fn_8020fd04 = 0x8020fd04;
lbl_80411a20 = 0x80411a20;
w3d_registry_804552b0 = 0x804552b0;
SECTIONS {
  .text.w3d_singleton_create_801655fc 0x801655fc : { *(.text.w3d_singleton_create_801655fc) }
  .sdata 0x804ab4ec (NOLOAD) : {
    . = 0x0; w3d_singleton_804ab4ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
