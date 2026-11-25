/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc44a_input_event_80160cd8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc44a_axis_80160708 = 0x80160708;
cc44a_press_80160628 = 0x80160628;
cc44a_release_80160698 = 0x80160698;
SECTIONS {
  .text.cc44a_input_event_80160cd8 0x80160cd8 : { *(.text.cc44a_input_event_80160cd8) }
  .rodata 0x803a467c : { *(.rodata) }
  .sdata 0x804b17f0 (NOLOAD) : {
    . = 0x0; cc44a_input_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
