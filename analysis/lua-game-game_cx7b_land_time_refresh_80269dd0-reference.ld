/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7b_land_time_refresh_80269dd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc230 = 0x800fc230;
fn_8026b9bc = 0x8026b9bc;
fn_8026c008 = 0x8026c008;
text_803cb980 = 0x803cb980;
SECTIONS {
  .text.w3d_cx7b_land_time_refresh_80269dd0 0x80269dd0 : { *(.text.w3d_cx7b_land_time_refresh_80269dd0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
