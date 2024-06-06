#!/usr/bin/env bash

set -e

cmd="${1:-yes}"
arg="${2:-y}"
count="${3:-5000}"

h1=$("$cmd" "$arg" | head -c "$count" | sha256sum)
h2=$(yes "$arg" | head -c "$count" | sha256sum)

echo "$h1"
echo "$h2"

if [[ "$h1" == "$h2" ]]
then
	true
else
	false
fi
