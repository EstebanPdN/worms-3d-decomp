/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_water_setup_800c9e14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
append_801ef174 = 0x801ef174;
cast_8034357c = 0x8034357c;
color_8043ed74 = 0x8043ed74;
color_8043ed84 = 0x8043ed84;
color_8043ed94 = 0x8043ed94;
create_8020b680 = 0x8020b680;
forward_801750f4 = 0x801750f4;
h_8043eda4 = 0x8043eda4;
h_8043eda8 = 0x8043eda8;
h_8043edb0 = 0x8043edb0;
k80413db0 = 0x80413db0;
k804143e0 = 0x804143e0;
k804144f8 = 0x804144f8;
k80414518 = 0x80414518;
k804146e0 = 0x804146e0;
k80414780 = 0x80414780;
k80414830 = 0x80414830;
k80414870 = 0x80414870;
k804148d0 = 0x804148d0;
k804149f0 = 0x804149f0;
k80415b30 = 0x80415b30;
k80415ba0 = 0x80415ba0;
k80415c00 = 0x80415c00;
k80415c30 = 0x80415c30;
k80415cb0 = 0x80415cb0;
load_8015adf4 = 0x8015adf4;
lookup_80174074 = 0x80174074;
reserve_801ef048 = 0x801ef048;
service_8020b648 = 0x8020b648;
setting_800fc2b0 = 0x800fc2b0;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
value_80174050 = 0x80174050;
SECTIONS {
  .text.d32h_water_setup_800c9e14 0x800c9e14 : { *(.text.d32h_water_setup_800c9e14) }
  .rodata 0x80387c40 : { *(.rodata) }
  .sdata 0x804ae800 (NOLOAD) : {
    . = 0x0; guard_804ae800 = .;
    . = 0x4; guard_804ae804 = .;
    . = 0x8; guard_804ae808 = .;
    . = 0x2f94; scene_804b1794 = .;
    . = 0x3130; token_804b1930 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
