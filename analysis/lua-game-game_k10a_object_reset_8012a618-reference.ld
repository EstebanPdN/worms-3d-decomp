/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_object_reset_8012a618)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800eac84 = 0x800eac84;
fn_800eb6e4 = 0x800eb6e4;
s8_post_object_events_800ed090 = 0x800ed090;
w3d_auto_801797b4 = 0x801797b4;
w3d_empty_80341584 = 0x80341584;
w3d_s20_play_sound_pair_800edca0 = 0x800edca0;
SECTIONS {
  .text.w3d_k10a_object_reset_8012a618 0x8012a618 : { *(.text.w3d_k10a_object_reset_8012a618) }
  .rodata 0x8039d228 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
