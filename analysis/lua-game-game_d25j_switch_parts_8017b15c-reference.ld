/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25j_switch_parts_8017b15c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017b6dc = 0x8017b6dc;
fn_801ef174 = 0x801ef174;
fn_801ef380 = 0x801ef380;
SECTIONS {
  .text.d25j_switch_parts_8017b15c 0x8017b15c : { *(.text.d25j_switch_parts_8017b15c) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; service_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
