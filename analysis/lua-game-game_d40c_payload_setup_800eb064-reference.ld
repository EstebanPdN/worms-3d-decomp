/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40c_payload_setup_800eb064)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
arm_800eb910 = 0x800eb910;
cached_id_8015f5a0 = 0x8015f5a0;
cast_801797b4 = 0x801797b4;
cast_80342a74 = 0x80342a74;
class_a_80361860 = 0x80361860;
class_c_803618f0 = 0x803618f0;
context_80165254 = 0x80165254;
copy_802eee50 = 0x802eee50;
empty_80341584 = 0x80341584;
forces_800eb6e4 = 0x800eb6e4;
handle_clock_801264fc = 0x801264fc;
handle_construct_801261bc = 0x801261bc;
handle_finish_80126524 = 0x80126524;
handle_owner_80126308 = 0x80126308;
handle_start_80126384 = 0x80126384;
heap_allocate_802098d8 = 0x802098d8;
log_80022e20 = 0x80022e20;
lookup_8003f240 = 0x8003f240;
malloc = 0x80212fd4;
move_800eac84 = 0x800eac84;
pick_800edd90 = 0x800edd90;
post_8016239c = 0x8016239c;
random_801610a0 = 0x801610a0;
read_setting_800fc1b0 = 0x800fc1b0;
release_802134fc = 0x802134fc;
s_aw_8038b44c = 0x8038b44c;
s_bm_8038b470 = 0x8038b470;
s_ed_8038b45c = 0x8038b45c;
s_g_8038b490 = 0x8038b490;
s_gs_8038b480 = 0x8038b480;
s_lg_8038b498 = 0x8038b498;
s_pf_8038b4c4 = 0x8038b4c4;
s_pl_8038b4b0 = 0x8038b4b0;
s_rn_8038b438 = 0x8038b438;
s_wd_8038b404 = 0x8038b404;
s_wl_8038b42c = 0x8038b42c;
s_wm_8038b420 = 0x8038b420;
s_ws_8038b414 = 0x8038b414;
speed_800ecf54 = 0x800ecf54;
subscribe_80162024 = 0x80162024;
target_801190b4 = 0x801190b4;
zero_8038b4dc = 0x8038b4dc;
SECTIONS {
  .text.d40c_payload_setup_800eb064 0x800eb064 : { *(.text.d40c_payload_setup_800eb064) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; kind_804aa95e = .;
    . = 0x45c2; c_804aef20 = .;
    . = 0x45e2; c_804aef40 = .;
    . = 0x45f2; c_804aef50 = .;
    . = 0x4c5e; heap_804af5bc = .;
    . = 0x6df6; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
