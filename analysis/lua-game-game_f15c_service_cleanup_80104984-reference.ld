/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f15c_service_cleanup_80104984)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015ff2c = 0x8015ff2c;
buffer_8044b694 = 0x8044b694;
copy_802eee50 = 0x802eee50;
vtable_80410690 = 0x80410690;
SECTIONS {
  .text.f15c_service_cleanup_80104984 0x80104984 : { *(.text.f15c_service_cleanup_80104984) }
  .sdata 0x804aafa4 (NOLOAD) : {
    . = 0x0; active_804aafa4 = .;
    . = 0x4244; selected_804af1e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
