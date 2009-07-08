%define version 6.0
%define dwarf_ver 20090324
%define xml2_ver 2.7.2

Summary: An API for Runtime Code Generation
License: Copyright 1996-2006 Barton P. Miller
Name: dyninst
Group: Development/Libraries
Prefix: %_usr
Provides: dyninst
Release: 1
Source: dyninst-%{version}.tar.gz
URL: http://www.dyninst.org
Version: %version
Packager: <bugs@dyninst.org>
Exclusiveos: linux

Source0: dyninst-%{version}.tar.gz
Source1: libdwarf-%{dwarf_ver}.tar.gz
Source2: libxml2-%{xml2_ver}.tar.gz

%description

Dyninst is an Application Program Interface (API) to permit the insertion of
code into a running program. The API also permits changing or removing
subroutine calls from the application program. Runtime code changes are
useful to support a variety of applications including debugging, performance
monitoring, and to support composing applications out of existing packages.
The goal of this API is to provide a machine independent interface to permit
the creation of tools and applications that use runtime code patching.

%prep

%define platform %{_arch}-unknown-linux2.4
%ifarch x86_64
	%define _lib lib64
%endif

%setup -q -a 1
%setup -q -T -D -a 2

%build

cd dwarf-%{dwarf_ver}/libdwarf; ./configure; make libdwarf.so
cd ../..
cd libxml2-%{xml2_ver}; ./configure; make
cd ..
cd dyninst

cat > make.config.local << RPMEOF
LIBDWARFDIR = %{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf
LIBDWARF_INC = %{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf
LIBDWARF_LIB = %{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf
LIBELFDIR = %_libdir
TCLTK_DIR = %_usr
LIBXML2_INC = %{_builddir}/%{buildsubdir}/libxml2-%{xml2_ver}/include
RPMEOF

make PLATFORM=%platform
make StackwalkerAPI PLATFORM=%platform

%install

%__install -d %{_includedir}/dyninst
%__install -d %{_libdir}/dyninst

cd dwarf-%{dwarf_ver}/libdwarf; 
%__install libdwarf.so %{_libdir}/dyninst
cd ../..

cd libxml2-%{xml2_ver}/lib; 
%__install libxml2.so %{_libdir}/dyninst
cd ../..

cd %{platform}/bin
%__install parseThat %{_bindir}
cd ../../lib
%__install libcommon.so %{_libdir}/dyninst
%__install libdyninstAPI_RT.so.1 %{_libdir}/dyninst
%__install libdyninstAPI.so %{_libdir}/dyninst
%__install libsymtabAPI.so %{_libdir}/dyninst
%__install libinstructionAPI.so %{_libdir}/dyninst
%__install libstackwalk.so %{_libdir}/dyninst
%ifarch x86_64
	%__install libdyninstAPI_RT_m32.so.1 %{_libdir}/dyninst
%endif
cd ../../include
%__install * %{_includedir}/dyninst

%clean

rm -rf $RPM_BUILD_ROOT

%files

%{_includedir}/dyninst
%{_libdir}/dyninst
%{_bindir}/parseThat

%{_libdir}/libdyninstAPI_RT.so.1

%ifarch x86_64
%{_libdir}/libdyninstAPI_RT_m32.so.1
%endif

%{_libdir}/libstackwalk.so

%{_libdir}/libdyninstAPI.so
%{_libdir}/libsymtabAPI.so
%{_libdir}/libcommon.so
%{_libdir}/libinstructionAPI.so
%doc dyninstProgGuide.pdf 

