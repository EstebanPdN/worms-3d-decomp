/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b32_countdown_800ff56c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fd388 = 0x800fd388;
fn_80178d1c = 0x80178d1c;
fn_80189760 = 0x80189760;
fn_8034380c = 0x8034380c;
SECTIONS {
  .text.tsonnet_b32_countdown_800ff56c 0x800ff56c : { *(.text.tsonnet_b32_countdown_800ff56c) }
  .sdata 0x804af158 (NOLOAD) : {
    . = 0x0; lbl_804af158 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
