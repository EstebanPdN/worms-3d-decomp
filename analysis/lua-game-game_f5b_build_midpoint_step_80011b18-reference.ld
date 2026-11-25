/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f5b_build_midpoint_step_80011b18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Queue_80003300 = 0x80003300;
__builtin_new = 0x8001523c;
fn_800033d8 = 0x800033d8;
fn_80003424 = 0x80003424;
fn_80003e78 = 0x80003e78;
fn_800108b8 = 0x800108b8;
half_8036a3b0 = 0x8036a3b0;
rise_8036a3b4 = 0x8036a3b4;
SECTIONS {
  .text.f5b_build_midpoint_step_80011b18 0x80011b18 : { *(.text.f5b_build_midpoint_step_80011b18) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; table_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
