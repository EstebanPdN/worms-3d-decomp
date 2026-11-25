/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_refresh_toggle_states_802a0ebc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8025f064 = 0x8025f064;
fn_8029459c = 0x8029459c;
fn_8029677c = 0x8029677c;
fn_802b2344 = 0x802b2344;
fn_802eefe0 = 0x802eefe0;
SECTIONS {
  .text.w3d_refresh_toggle_states_802a0ebc 0x802a0ebc : { *(.text.w3d_refresh_toggle_states_802a0ebc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
