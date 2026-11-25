/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40k_element_wrappers_80262a58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12Str_803426b8 = 0x803426b8;
class_8041bb20 = 0x8041bb20;
class_8041bbf0 = 0x8041bbf0;
class_8041bc80 = 0x8041bc80;
class_8041bd50 = 0x8041bd50;
class_8041bde0 = 0x8041bde0;
class_8041bf30 = 0x8041bf30;
class_8041c080 = 0x8041c080;
class_8041c110 = 0x8041c110;
class_8041c2a0 = 0x8041c2a0;
class_8041c338 = 0x8041c338;
class_8041c3d0 = 0x8041c3d0;
class_8041c460 = 0x8041c460;
class_8041c4f0 = 0x8041c4f0;
class_8041c580 = 0x8041c580;
class_8041c6a0 = 0x8041c6a0;
class_8041c730 = 0x8041c730;
class_8041c7c0 = 0x8041c7c0;
fn_800c4d9c = 0x800c4d9c;
fn_800fc1b0 = 0x800fc1b0;
fn_8010a8e0 = 0x8010a8e0;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80164514 = 0x80164514;
fn_801790bc = 0x801790bc;
fn_801797b4 = 0x801797b4;
fn_8020b680 = 0x8020b680;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802b1250 = 0x802b1250;
fn_802b1258 = 0x802b1258;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
lbl_803cac08 = 0x803cac08;
type_80365b28 = 0x80365b28;
type_80365b78 = 0x80365b78;
type_80365bc8 = 0x80365bc8;
type_80365c18 = 0x80365c18;
type_80365c68 = 0x80365c68;
type_80365cb8 = 0x80365cb8;
type_80365d08 = 0x80365d08;
type_80365d58 = 0x80365d58;
type_80365da8 = 0x80365da8;
type_80365df8 = 0x80365df8;
type_80365e48 = 0x80365e48;
type_80365e98 = 0x80365e98;
type_80365ee8 = 0x80365ee8;
type_80365f38 = 0x80365f38;
type_80365f88 = 0x80365f88;
type_80365fd8 = 0x80365fd8;
type_80366028 = 0x80366028;
type_80366078 = 0x80366078;
SECTIONS {
  .text.w3d_d40k_element_wrappers_80262a58 0x80262a58 : { *(.text.w3d_d40k_element_wrappers_80262a58) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; lbl_804abb5c = .;
    . = 0x4e18; lbl_804b0974 = .;
    . = 0x5bf8; lbl_804b1754 = .;
    . = 0x5c30; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
