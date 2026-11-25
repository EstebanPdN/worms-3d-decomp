/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_scene_teardown_80127a0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fbf64 = 0x800fbf64;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80164f88 = 0x80164f88;
w3d_auto_802cc58c = 0x802cc58c;
w3d_empty_80128084 = 0x80128084;
w3d_engine_get_context = 0x80165254;
w3d_runtime_owner_finish = 0x8015c880;
SECTIONS {
  .text.w3d_k10a_scene_teardown_80127a0c 0x80127a0c : { *(.text.w3d_k10a_scene_teardown_80127a0c) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; w3d_listener_804aaabc = .;
    . = 0xe8; w3d_listener_804aaba4 = .;
    . = 0x310; w3d_listener_804aadcc = .;
    . = 0x4cc; w3d_listener_804aaf88 = .;
    . = 0x548; w3d_listener_804ab004 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
