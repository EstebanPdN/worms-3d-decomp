/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__16Mx14oaFileOwnerB)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_vt.14Mx14oaServiceB = 0x804111a0;
_vt.16Mx14oaFileOwnerB = 0x80411168;
w3d_register_owner_80165594 = 0x80165594;
w3d_setting_80206920 = 0x80206920;
w3d_str_run_from_cd_803a4348 = 0x803a4348;
w3d_string_default = 0x803426b8;
SECTIONS {
  .text.__16Mx14oaFileOwnerB 0x8015be3c : { *(.text.__16Mx14oaFileOwnerB) }
  .sdata 0x804b17ec (NOLOAD) : {
    . = 0x0; w3d_file_owner_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
