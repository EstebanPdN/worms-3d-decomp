/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc30a_camera_visibility_80026064)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc30a_call_80181640 = 0x80181640;
cc30a_call_8018179c = 0x8018179c;
cc30a_call_801817e0 = 0x801817e0;
cc30a_float_8036c9cc = 0x8036c9cc;
cc30a_float_8036c9d0 = 0x8036c9d0;
cc30a_float_8036c9d4 = 0x8036c9d4;
SECTIONS {
  .text.cc30a_camera_visibility_80026064 0x80026064 : { *(.text.cc30a_camera_visibility_80026064) }
  .sdata 0x804aa7f4 (NOLOAD) : {
    . = 0x0; cc30a_name_804aa7f4 = .;
    . = 0x4; cc30a_name_804aa7f8 = .;
    . = 0x6f94; cc30a_global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
