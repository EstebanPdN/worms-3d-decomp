/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_attach_weapon_mesh_801394ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__as__6StringPCc = 0x8020bd38;
any_handle_8013f844 = 0x8013f844;
bind_8013e35c = 0x8013e35c;
cast_80343584 = 0x80343584;
clear_8013e3d4 = 0x8013e3d4;
finish_8020c5c4 = 0x8020c5c4;
play_80181640 = 0x80181640;
release_80341588 = 0x80341588;
set_lights_80182410 = 0x80182410;
set_name_8015adf4 = 0x8015adf4;
SECTIONS {
  .text.d28d_worm_attach_weapon_mesh_801394ac 0x801394ac : { *(.text.d28d_worm_attach_weapon_mesh_801394ac) }
  .rodata 0x8039f678 : { *(.rodata) }
  .sdata 0x804ab32c (NOLOAD) : {
    . = 0x0; nm_804ab32c = .;
    . = 0x10; nA_804ab33c = .;
    . = 0x14; nB_804ab340 = .;
    . = 0x18; nC_804ab344 = .;
    . = 0x1c; nD_804ab348 = .;
    . = 0x20; nE_804ab34c = .;
    . = 0x24; nF_804ab350 = .;
    . = 0x28; nG_804ab354 = .;
    . = 0x2c; nH_804ab358 = .;
    . = 0x30; nI_804ab35c = .;
    . = 0x34; nJ_804ab360 = .;
    . = 0x38; nK_804ab364 = .;
    . = 0x3c; nL_804ab368 = .;
    . = 0x40; nM_804ab36c = .;
    . = 0x44; nN_804ab370 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
