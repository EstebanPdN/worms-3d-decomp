/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15a_probe_actor_80017c38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
position_8041d3a0 = 0x8041d3a0;
probe_80009674 = 0x80009674;
SECTIONS {
  .text.w3d_cx15a_probe_actor_80017c38 0x80017c38 : { *(.text.w3d_cx15a_probe_actor_80017c38) }
  .sdata 0x804aa5a0 (NOLOAD) : {
    . = 0x0; active_804aa5a0 = .;
    . = 0x138; parameters_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
