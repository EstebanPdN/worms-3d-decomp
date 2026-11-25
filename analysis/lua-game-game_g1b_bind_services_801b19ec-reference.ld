/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g1b_bind_services_801b19ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f2798 = 0x801f2798;
fn_8020b648 = 0x8020b648;
fn_8020b680 = 0x8020b680;
key_80413be8 = 0x80413be8;
key_804143e0 = 0x804143e0;
SECTIONS {
  .text.g1b_bind_services_801b19ec 0x801b19ec : { *(.text.g1b_bind_services_801b19ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
