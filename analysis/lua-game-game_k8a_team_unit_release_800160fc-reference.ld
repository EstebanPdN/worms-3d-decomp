/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_team_unit_release_800160fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80015588 = 0x80015588;
w3d_auto_800155ac = 0x800155ac;
w3d_auto_80015d18 = 0x80015d18;
w3d_cx9a_storage_push_global_8001634c = 0x8001634c;
w3d_unit_finish_800161d8 = 0x800161d8;
SECTIONS {
  .text.w3d_k8a_team_unit_release_800160fc 0x800160fc : { *(.text.w3d_k8a_team_unit_release_800160fc) }
  .sdata 0x804aa6f4 (NOLOAD) : {
    . = 0x0; w3d_unit_804aa6f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
