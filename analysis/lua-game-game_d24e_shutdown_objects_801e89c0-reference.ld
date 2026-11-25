/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24e_shutdown_objects_801e89c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8ccc = 0x801e8ccc;
fn_801ea954 = 0x801ea954;
fn_801ea9a4 = 0x801ea9a4;
fn_802134fc = 0x802134fc;
memcpy = 0x802eee50;
table_8045e080 = 0x8045e080;
SECTIONS {
  .text.w3d_d24e_shutdown_objects_801e89c0 0x801e89c0 : { *(.text.w3d_d24e_shutdown_objects_801e89c0) }
  .sdata 0x804b18e0 (NOLOAD) : {
    . = 0x0; first_804b18e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
