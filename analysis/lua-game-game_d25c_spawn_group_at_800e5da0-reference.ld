/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_spawn_group_at_800e5da0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80164514 = 0x80164514;
forward_8020b680 = 0x8020b680;
key_8040ffa8 = 0x8040ffa8;
key_80410048 = 0x80410048;
key_804106c0 = 0x804106c0;
load_800df6a4 = 0x800df6a4;
read_800fc330 = 0x800fc330;
type_803678d8 = 0x803678d8;
SECTIONS {
  .text.d25c_spawn_group_at_800e5da0 0x800e5da0 : { *(.text.d25c_spawn_group_at_800e5da0) }
  .sdata 0x804aaec8 (NOLOAD) : {
    . = 0x0; counter_804aaec8 = .;
    . = 0x68c4; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
