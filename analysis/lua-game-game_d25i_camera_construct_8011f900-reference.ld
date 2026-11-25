/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_camera_construct_8011f900)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
as_definition_80341584 = 0x80341584;
base_8015a6b8 = 0x8015a6b8;
cached_id_8015f5a0 = 0x8015f5a0;
camera_update_80120648 = 0x80120648;
definition_801797b4 = 0x801797b4;
find_task_80164fc8 = 0x80164fc8;
message_init_8010a8e0 = 0x8010a8e0;
message_post_8016239c = 0x8016239c;
n_8039b5f0 = 0x8039b5f0;
n_8039b608 = 0x8039b608;
n_8039b614 = 0x8039b614;
n_8039b620 = 0x8039b620;
n_8039b630 = 0x8039b630;
n_8039b638 = 0x8039b638;
n_8039b640 = 0x8039b640;
n_8039b64c = 0x8039b64c;
n_8039b65c = 0x8039b65c;
n_8039b668 = 0x8039b668;
n_8039b680 = 0x8039b680;
read_key_800fc2b0 = 0x800fc2b0;
read_setting_800fc1b0 = 0x800fc1b0;
read_task_800fc230 = 0x800fc230;
type_80360e10 = 0x80360e10;
SECTIONS {
  .text.d25i_camera_construct_8011f900 0x8011f900 : { *(.text.d25i_camera_construct_8011f900) }
  .sdata 0x804af4b4 (NOLOAD) : {
    . = 0x0; cache_804af4b4 = .;
    . = 0x8; cache_804af4bc = .;
    . = 0x22a0; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
