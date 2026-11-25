/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_sound_debug_destroy_80051d18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_802cc58c = 0x802cc58c;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_vtable_8040eb60 = 0x8040eb60;
SECTIONS {
  .text.w3d_k8a_sound_debug_destroy_80051d18 0x80051d18 : { *(.text.w3d_k8a_sound_debug_destroy_80051d18) }
  .sdata 0x804aaa10 (NOLOAD) : {
    . = 0x0; w3d_sound_debug_804aaa10 = .;
    . = 0x4; w3d_output_804aaa14 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
