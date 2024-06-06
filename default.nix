{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
  pname = "hell-yeah";
  version = "0.0.1";

  src = ./.;

  mesonBuildType = "release";
  
  nativeBuildInputs = [
    pkgs.shellcheck
    pkgs.timelimit
    pkgs.meson
    pkgs.ninja
  ];

  buildInputs = [
    pkgs.gcc
  ];
}
