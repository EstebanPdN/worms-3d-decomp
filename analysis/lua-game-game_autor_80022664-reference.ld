/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80022664)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80164FC8 = 0x80164fc8;
fn_80165254 = 0x80165254;
fn_80182410 = 0x80182410;
fn_802134FC = 0x802134fc;
fn_802E4D04 = 0x802e4d04;
fn_802EEE50 = 0x802eee50;
SECTIONS {
  .text.w3d_auto_80022664 0x80022664 : { *(.text.w3d_auto_80022664) }
  .text.w3d_auto_8006f0dc 0x8006f0dc : { *(.text.w3d_auto_8006f0dc) }
  .text.w3d_auto_801399b4 0x801399b4 : { *(.text.w3d_auto_801399b4) }
  .text.w3d_auto_80178ad4 0x80178ad4 : { *(.text.w3d_auto_80178ad4) }
  .text.w3d_auto_80178b5c 0x80178b5c : { *(.text.w3d_auto_80178b5c) }
  .text.w3d_auto_801fc86c 0x801fc86c : { *(.text.w3d_auto_801fc86c) }
  .text.w3d_auto_80208d30 0x80208d30 : { *(.text.w3d_auto_80208d30) }
  .text.w3d_auto_80209720 0x80209720 : { *(.text.w3d_auto_80209720) }
  .text.w3d_auto_80209de4 0x80209de4 : { *(.text.w3d_auto_80209de4) }
  .text.w3d_auto_8020c5cc 0x8020c5cc : { *(.text.w3d_auto_8020c5cc) }
  .text.w3d_auto_80215f2c 0x80215f2c : { *(.text.w3d_auto_80215f2c) }
  .text.w3d_auto_802190d4 0x802190d4 : { *(.text.w3d_auto_802190d4) }
  .text.w3d_auto_80351ea0 0x80351ea0 : { *(.text.w3d_auto_80351ea0) }
  .text.w3d_auto_80351f50 0x80351f50 : { *(.text.w3d_auto_80351f50) }
  .text.w3d_auto_80351fb0 0x80351fb0 : { *(.text.w3d_auto_80351fb0) }
  .text.w3d_auto_80352f34 0x80352f34 : { *(.text.w3d_auto_80352f34) }
  .text.w3d_auto_80355800 0x80355800 : { *(.text.w3d_auto_80355800) }
  .text.w3d_auto_8035b2d4 0x8035b2d4 : { *(.text.w3d_auto_8035b2d4) }
  .text.w3d_auto_8035b84c 0x8035b84c : { *(.text.w3d_auto_8035b84c) }
  .text.w3d_auto_8035b8a4 0x8035b8a4 : { *(.text.w3d_auto_8035b8a4) }
  .text.w3d_auto_8035cc1c 0x8035cc1c : { *(.text.w3d_auto_8035cc1c) }
  .sdata 0x804b05d8 (NOLOAD) : {
    . = 0x0; lbl_804B05D8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
