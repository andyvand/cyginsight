%define version 7.0.1

Summary: An API for Run-time Code Generation
License: LGPLv2+
Name: dyninst
Group: Development/Libraries
Release: 0.7%{?dist}git
URL: http://www.dyninst.org
Version: %version
Exclusiveos: linux
#Right now dyninst does not know about the following architectures
ExcludeArch: s390 s390x %{arm}

Source0: http://www.dyninst.org/sites/default/files/downloads/dyninst/%{name}-%{version}.tar.gz
BuildRequires: libxml2-devel >= 2.7.8
BuildRequires: libdwarf-devel 
BuildRequires: elfutils-libelf-devel
BuildRequires: boost-devel

%description

Dyninst is an Application Program Interface (API) to permit the insertion of
code into a running program. The API also permits changing or removing
subroutine calls from the application program. Run-time code changes are
useful to support a variety of applications including debugging, performance
monitoring, and to support composing applications out of existing packages.
The goal of this API is to provide a machine independent interface to permit
the creation of tools and applications that use run-time code patching.

%package devel
Summary: Header files for the compiling programs with Dyninst
Group: Development/System
Requires: dyninst = %{version}-%{release}
%description devel
Dyninst-devel includes the C header files that specify the Dyninst user-space
libraries and interfaces. This is required for rebuilding any program
that uses Dyninst.

%package static
Summary: Static libraries for the compiling programs with Dyninst
Group: Development/System
Requires: dyninst = %{version}-%{release}
%description static
dyninst-static includes the static versions of the library files for
the dyninst user-space libraries and interfaces.

%prep
%setup -q

#FIXME ugly hack to remove the boost files
#pushd dyninst/external; rm -rf boost; popd
#pushd src/dyninst/dynutil/h/dyn_detail; rm -rf boost; popd

%build

cd dyninst

%configure
make \
  LIBRARY_DEST=%{buildroot}/%{_libdir}/dyninst \
  PROGRAM_DEST=%{buildroot}/usr/bin \
  INCLUDE_DEST=%{buildroot}/usr/include/dyninst \
  DONT_BUILD_NEWTESTSUITE=1 \
  all StackwalkerAPI
# FIXME parseThat not built as part of normal build now
#pushd parseThat
#  make \
#    LIBRARY_DEST=%{buildroot}/%{_libdir}/dyninst \
#    PROGRAM_DEST=%{buildroot}/usr/bin \
#    INCLUDE_DEST=%{buildroot}/usr/include/dyninst \
#    DONT_BUILD_NEWTESTSUITE=1
#popd

%install

#FIXME Really should be able to do something like the following
cd dyninst
make \
  LIBRARY_DEST=%{buildroot}/%{_libdir}/dyninst \
  PROGRAM_DEST=%{buildroot}/usr/bin \
  INCLUDE_DEST=%{buildroot}/usr/include/dyninst \
  DONT_BUILD_NEWTESTSUITE=1 \
  install
# FIXME parseThat not built as part of normal build now
#pushd parseThat
#   make \
#     LIBRARY_DEST=%{buildroot}/%{_libdir}/dyninst \
#     PROGRAM_DEST=%{buildroot}/usr/bin \
#     INCLUDE_DEST=%{buildroot}/usr/include/dyninst \
#     DONT_BUILD_NEWTESTSUITE=1 \
#     install
#popd

#%__install -d %{buildroot}/%{_bindir}
#%__install dyninst/parseThat/%{platform}/parseThat %{buildroot}/%{_bindir}
#
#%__install -d %{buildroot}/%{_libdir}/dyninst
#%__install %{platform}/lib/* %{buildroot}/%{_libdir}/dyninst
#
#%__install -d %{buildroot}/%{_includedir}/dyninst
#cp -pr include/* %{buildroot}/%{_includedir}/dyninst

mkdir -p %{buildroot}/etc/ld.so.conf.d
echo "%{_libdir}/dyninst" > %{buildroot}/etc/ld.so.conf.d/%{name}-%{_arch}.conf

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig
%clean

rm -rf %{buildroot}

%files
%defattr(-,root,root,-)

# FIXME parseThat is not part of normal build
#%{_bindir}/parseThat
%{_libdir}/dyninst/*.so*

#FIXME need LICENSE and README files in tarball
#%doc LICENSE
#%doc README

%doc depGraphAPI.pdf
%doc dynC_API.pdf
%doc dyninstProgGuide.pdf
%doc symtabProgGuide.pdf
%doc instructionProgGuide.pdf
%doc parseapi.pdf
%doc ProcControlAPI.pdf
%doc stackwalker.pdf
%doc dynC_API.pdf

%config(noreplace) /etc/ld.so.conf.d/*

%files devel
%defattr(-,root,root,-)
%{_includedir}/dyninst

%files static
%defattr(-,root,root,-)
%{_libdir}/dyninst/*.a

%changelog
* Wed May 2 2012 William Cohen <wcohen@redhat.com> - 7.0.1-0.7
- Use "make install" and do staged build.
- Use rpm configure macro.

* Thu Mar 15 2012 William Cohen <wcohen@redhat.com> - 7.0.1-0.5
- Nuke the bundled boost files and use the boost-devel rpm instead.

* Mon Mar 12 2012 William Cohen <wcohen@redhat.com> - 7.0.1-0.4
- Initial submission of dyninst spec file.
