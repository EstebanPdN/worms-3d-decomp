/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_singleton_create_802058ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18w3d_class_80205a40 = 0x80205a40;
__nw__18w3d_class_80205a40Ui = 0x801fe1d8;
fn_8020593c = 0x8020593c;
fn_80205964 = 0x80205964;
fn_8020b648 = 0x8020b648;
fn_8020fd04 = 0x8020fd04;
lbl_804190e0 = 0x804190e0;
w3d_registry_8045edf4 = 0x8045edf4;
SECTIONS {
  .text.w3d_singleton_create_802058ac 0x802058ac : { *(.text.w3d_singleton_create_802058ac) }
  .sdata 0x804ab98c (NOLOAD) : {
    . = 0x0; w3d_singleton_804ab98c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
