/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_message_route_800fe408)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002aa48 = 0x8002aa48;
fn_800fe4b4 = 0x800fe4b4;
fn_800fe4fc = 0x800fe4fc;
fn_800fe5b0 = 0x800fe5b0;
fn_8015f65c = 0x8015f65c;
SECTIONS {
  .text.s8_message_route_800fe408 0x800fe408 : { *(.text.s8_message_route_800fe408) }
  .sdata 0x804af14c (NOLOAD) : {
    . = 0x0; lbl_804af14c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
