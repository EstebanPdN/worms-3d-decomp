/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_write_double_80204224)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1d8 = 0x801fe1d8;
fn_802047e0 = 0x802047e0;
fn_80208c0c = 0x80208c0c;
fn_80208f48 = 0x80208f48;
fn_8020b648 = 0x8020b648;
SECTIONS {
  .text.w3d_s10_write_double_80204224 0x80204224 : { *(.text.w3d_s10_write_double_80204224) }
  .text.w3d_s10_create_entry_80208aac 0x80208aac : { *(.text.w3d_s10_create_entry_80208aac) }
  .text.w3d_s10_service_forward_8020b680 0x8020b680 : { *(.text.w3d_s10_service_forward_8020b680) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
