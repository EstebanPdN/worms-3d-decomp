/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80051930)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015ff7c = 0x8015ff7c;
w3d_ctor_801628b0 = 0x801628b0;
w3d_f32_80378188 = 0x80378188;
w3d_f32_8037818c = 0x8037818c;
w3d_f32_80378190 = 0x80378190;
w3d_f32_80378198 = 0x80378198;
w3d_fn_802cc4f0 = 0x802cc4f0;
w3d_fn_802e86d4 = 0x802e86d4;
w3d_fn_802e88ac = 0x802e88ac;
w3d_str_803781c0 = 0x803781c0;
w3d_vtable_8040eb60 = 0x8040eb60;
SECTIONS {
  .text.w3d_fn_80051930 0x80051930 : { *(.text.w3d_fn_80051930) }
  .text.w3d_fn_80051a24 0x80051a24 : { *(.text.w3d_fn_80051a24) }
  .text.w3d_fn_80051c9c 0x80051c9c : { *(.text.w3d_fn_80051c9c) }
  .rodata 0x80378180 : { *(.rodata) }
  .sdata 0x804aaa10 (NOLOAD) : {
    . = 0x0; w3d_sound_debug_804aaa10 = .;
    . = 0x4; w3d_output_804aaa14 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
