/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_message_route_8009aa08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8009af20 = 0x8009af20;
fn_8009af9c = 0x8009af9c;
fn_8015f65c = 0x8015f65c;
fn_8015fb34 = 0x8015fb34;
fn_8015fd1c = 0x8015fd1c;
SECTIONS {
  .text.s8_message_route_8009aa08 0x8009aa08 : { *(.text.s8_message_route_8009aa08) }
  .sdata 0x804adfc4 (NOLOAD) : {
    . = 0x0; lbl_804adfc4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
