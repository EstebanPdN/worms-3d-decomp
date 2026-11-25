/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28i_scene_start_80126e4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
ambient_80450a54 = 0x80450a54;
bind_8015cd34 = 0x8015cd34;
colour_8045e788 = 0x8045e788;
create_80164514 = 0x80164514;
endpoint_802cc4f0 = 0x802cc4f0;
euler_801a3eb0 = 0x801a3eb0;
font_8015c8dc = 0x8015c8dc;
lightType_804138c0 = 0x804138c0;
make_8020b680 = 0x8020b680;
post_80128f68 = 0x80128f68;
pre_8015cabc = 0x8015cabc;
reset_800fbd48 = 0x800fbd48;
spec_8045e7a0 = 0x8045e7a0;
type_8040e238 = 0x8040e238;
type_8040ead0 = 0x8040ead0;
type_8040f300 = 0x8040f300;
type_8040f918 = 0x8040f918;
type_80411018 = 0x80411018;
SECTIONS {
  .text.d28i_scene_start_80126e4c 0x80126e4c : { *(.text.d28i_scene_start_80126e4c) }
  .rodata 0x8039bc78 : { *(.rodata) }
  .sdata 0x804aa828 (NOLOAD) : {
    . = 0x0; type_804aa828 = .;
    . = 0x3ac; commands_804aabd4 = .;
    . = 0x760; endpoint_804aaf88 = .;
    . = 0x4d90; ambient_ready_804af5b8 = .;
    . = 0x6f64; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
