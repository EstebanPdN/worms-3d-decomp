/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_clip_frames_8002f764)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_clip_length_8017fc90 = 0x8017fc90;
w3d_empty_80341348 = 0x80341348;
w3d_f32_80372f38 = 0x80372f38;
w3d_runtime_service_lookup = 0x8015ae3c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k7a_clip_frames_8002f764 0x8002f764 : { *(.text.w3d_k7a_clip_frames_8002f764) }
  .sdata 0x804aa894 (NOLOAD) : {
    . = 0x0; w3d_clip_library_name_804aa894 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
