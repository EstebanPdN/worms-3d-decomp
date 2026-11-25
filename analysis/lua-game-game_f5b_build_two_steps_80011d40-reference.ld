/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f5b_build_two_steps_80011d40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Queue_80003300 = 0x80003300;
__builtin_new = 0x8001523c;
duration_8036a3e8 = 0x8036a3e8;
fn_800033d8 = 0x800033d8;
fn_80003424 = 0x80003424;
fn_80003710 = 0x80003710;
fn_80003e78 = 0x80003e78;
fn_800108b8 = 0x800108b8;
half_8036a3e4 = 0x8036a3e4;
rise_8036a3ec = 0x8036a3ec;
SECTIONS {
  .text.f5b_build_two_steps_80011d40 0x80011d40 : { *(.text.f5b_build_two_steps_80011d40) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; table_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
