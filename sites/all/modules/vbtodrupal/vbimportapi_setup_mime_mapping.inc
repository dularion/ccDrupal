<?php

/**
 * Set up a temporary table containing MIME to filename extension mappings.
 */
function vbimportapi_setup_mime_mapping() {
  db_query("CREATE TEMPORARY TABLE mime_mapping (
    extension varchar(255) NOT NULL default '',
    mime varchar(255) NOT NULL default '')");

  $mime_insert = db_insert('mime_mapping')->fields(array('extension', 'mime'));
  $mime_data = array(
    array('extension' => 'ez', 'mime' => 'application/andrew-inset'),
    array('extension' => 'atom', 'mime' => 'application/atom'),
    array('extension' => 'atomcat', 'mime' => 'application/atomcat+xml'),
    array('extension' => 'atomsrv', 'mime' => 'application/atomserv+xml'),
    array('extension' => 'cap', 'mime' => 'application/cap'),
    array('extension' => 'pcap', 'mime' => 'application/cap'),
    array('extension' => 'cu', 'mime' => 'application/cu-seeme'),
    array('extension' => 'tsp', 'mime' => 'application/dsptype'),
    array('extension' => 'spl', 'mime' => 'application/x-futuresplash'),
    array('extension' => 'hta', 'mime' => 'application/hta'),
    array('extension' => 'jar', 'mime' => 'application/java-archive'),
    array('extension' => 'ser', 'mime' => 'application/java-serialized-object'),
    array('extension' => 'class', 'mime' => 'application/java-vm'),
    array('extension' => 'hqx', 'mime' => 'application/mac-binhex40'),
    array('extension' => 'cpt', 'mime' => 'image/x-corelphotopaint'),
    array('extension' => 'nb', 'mime' => 'application/mathematica'),
    array('extension' => 'mdb', 'mime' => 'application/msaccess'),
    array('extension' => 'doc', 'mime' => 'application/msword'),
    array('extension' => 'dot', 'mime' => 'application/msword'),
    array('extension' => 'bin', 'mime' => 'application/octet-stream'),
    array('extension' => 'oda', 'mime' => 'application/oda'),
    array('extension' => 'ogg', 'mime' => 'application/ogg'),
    array('extension' => 'ogx', 'mime' => 'application/ogg'),
    array('extension' => 'pdf', 'mime' => 'application/pdf'),
    array('extension' => 'key', 'mime' => 'application/pgp-keys'),
    array('extension' => 'pgp', 'mime' => 'application/pgp-signature'),
    array('extension' => 'prf', 'mime' => 'application/pics-rules'),
    array('extension' => 'ps', 'mime' => 'application/postscript'),
    array('extension' => 'ai', 'mime' => 'application/postscript'),
    array('extension' => 'eps', 'mime' => 'application/postscript'),
    array('extension' => 'rar', 'mime' => 'application/rar'),
    array('extension' => 'rdf', 'mime' => 'application/rdf+xml'),
    array('extension' => 'rss', 'mime' => 'application/rss+xml'),
    array('extension' => 'rtf', 'mime' => 'application/rtf'),
    array('extension' => 'smi', 'mime' => 'application/smil'),
    array('extension' => 'smil', 'mime' => 'application/smil'),
    array('extension' => 'wpd', 'mime' => 'application/wordperfect'),
    array('extension' => 'wp5', 'mime' => 'application/wordperfect5.1'),
    array('extension' => 'xhtml', 'mime' => 'application/xhtml+xml'),
    array('extension' => 'xht', 'mime' => 'application/xhtml+xml'),
    array('extension' => 'xml', 'mime' => 'application/xml'),
    array('extension' => 'xsl', 'mime' => 'application/xml'),
    array('extension' => 'zip', 'mime' => 'application/zip'),
    array('extension' => 'cdy', 'mime' => 'application/vnd.cinderella'),
    array('extension' => 'kml', 'mime' => 'application/vnd.google-earth.kml+xml'),
    array('extension' => 'kmz', 'mime' => 'application/vnd.google-earth.kmz'),
    array('extension' => 'xul', 'mime' => 'application/vnd.mozilla.xul+xml'),
    array('extension' => 'xls', 'mime' => 'application/vnd.ms-excel'),
    array('extension' => 'xlb', 'mime' => 'application/vnd.ms-excel'),
    array('extension' => 'xlt', 'mime' => 'application/vnd.ms-excel'),
    array('extension' => 'cat', 'mime' => 'application/vnd.ms-pki.seccat'),
    array('extension' => 'stl', 'mime' => 'application/vnd.ms-pki.stl'),
    array('extension' => 'ppt', 'mime' => 'application/vnd.ms-powerpoint'),
    array('extension' => 'pps', 'mime' => 'application/vnd.ms-powerpoint'),
    array('extension' => 'odc', 'mime' => 'application/vnd.oasis.opendocument.chart'),
    array('extension' => 'odb', 'mime' => 'application/vnd.oasis.opendocument.database'),
    array('extension' => 'odf', 'mime' => 'application/vnd.oasis.opendocument.formula'),
    array('extension' => 'odg', 'mime' => 'application/vnd.oasis.opendocument.graphics'),
    array('extension' => 'otg', 'mime' => 'application/vnd.oasis.opendocument.graphics-template'),
    array('extension' => 'odi', 'mime' => 'application/vnd.oasis.opendocument.image'),
    array('extension' => 'odp', 'mime' => 'application/vnd.oasis.opendocument.presentation'),
    array('extension' => 'otp', 'mime' => 'application/vnd.oasis.opendocument.presentation-template'),
    array('extension' => 'ods', 'mime' => 'application/vnd.oasis.opendocument.spreadsheet'),
    array('extension' => 'ots', 'mime' => 'application/vnd.oasis.opendocument.spreadsheet-template'),
    array('extension' => 'odt', 'mime' => 'application/vnd.oasis.opendocument.text'),
    array('extension' => 'odm', 'mime' => 'application/vnd.oasis.opendocument.text-master'),
    array('extension' => 'ott', 'mime' => 'application/vnd.oasis.opendocument.text-template'),
    array('extension' => 'oth', 'mime' => 'application/vnd.oasis.opendocument.text-web'),
    array('extension' => 'docm', 'mime' => 'application/vnd.ms-word.document.macroEnabled.12'),
    array('extension' => 'docx', 'mime' => 'application/vnd.openxmlformats-officedocument.wordprocessingml.document'),
    array('extension' => 'dotm', 'mime' => 'application/vnd.ms-word.template.macroEnabled.12'),
    array('extension' => 'dotx', 'mime' => 'application/vnd.openxmlformats-officedocument.wordprocessingml.template'),
    array('extension' => 'potm', 'mime' => 'application/vnd.ms-powerpoint.template.macroEnabled.12'),
    array('extension' => 'potx', 'mime' => 'application/vnd.openxmlformats-officedocument.presentationml.template'),
    array('extension' => 'ppam', 'mime' => 'application/vnd.ms-powerpoint.addin.macroEnabled.12'),
    array('extension' => 'ppsm', 'mime' => 'application/vnd.ms-powerpoint.slideshow.macroEnabled.12'),
    array('extension' => 'ppsx', 'mime' => 'application/vnd.openxmlformats-officedocument.presentationml.slideshow'),
    array('extension' => 'pptm', 'mime' => 'application/vnd.ms-powerpoint.presentation.macroEnabled.12'),
    array('extension' => 'pptx', 'mime' => 'application/vnd.openxmlformats-officedocument.presentationml.presentation'),
    array('extension' => 'xlam', 'mime' => 'application/vnd.ms-excel.addin.macroEnabled.12'),
    array('extension' => 'xlsb', 'mime' => 'application/vnd.ms-excel.sheet.binary.macroEnabled.12'),
    array('extension' => 'xlsm', 'mime' => 'application/vnd.ms-excel.sheet.macroEnabled.12'),
    array('extension' => 'xlsx', 'mime' => 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet'),
    array('extension' => 'xltm', 'mime' => 'application/vnd.ms-excel.template.macroEnabled.12'),
    array('extension' => 'xltx', 'mime' => 'application/vnd.openxmlformats-officedocument.spreadsheetml.template'),
    array('extension' => 'cod', 'mime' => 'application/vnd.rim.cod'),
    array('extension' => 'mmf', 'mime' => 'application/vnd.smaf'),
    array('extension' => 'sdc', 'mime' => 'application/vnd.stardivision.calc'),
    array('extension' => 'sds', 'mime' => 'application/vnd.stardivision.chart'),
    array('extension' => 'sda', 'mime' => 'application/vnd.stardivision.draw'),
    array('extension' => 'sdd', 'mime' => 'application/vnd.stardivision.impress'),
    array('extension' => 'sdf', 'mime' => 'application/vnd.stardivision.math'),
    array('extension' => 'sdw', 'mime' => 'application/vnd.stardivision.writer'),
    array('extension' => 'sgl', 'mime' => 'application/vnd.stardivision.writer-global'),
    array('extension' => 'sxc', 'mime' => 'application/vnd.sun.xml.calc'),
    array('extension' => 'stc', 'mime' => 'application/vnd.sun.xml.calc.template'),
    array('extension' => 'sxd', 'mime' => 'application/vnd.sun.xml.draw'),
    array('extension' => 'std', 'mime' => 'application/vnd.sun.xml.draw.template'),
    array('extension' => 'sxi', 'mime' => 'application/vnd.sun.xml.impress'),
    array('extension' => 'sti', 'mime' => 'application/vnd.sun.xml.impress.template'),
    array('extension' => 'sxm', 'mime' => 'application/vnd.sun.xml.math'),
    array('extension' => 'sxw', 'mime' => 'application/vnd.sun.xml.writer'),
    array('extension' => 'sxg', 'mime' => 'application/vnd.sun.xml.writer.global'),
    array('extension' => 'stw', 'mime' => 'application/vnd.sun.xml.writer.template'),
    array('extension' => 'sis', 'mime' => 'application/vnd.symbian.install'),
    array('extension' => 'vsd', 'mime' => 'application/vnd.visio'),
    array('extension' => 'wbxml', 'mime' => 'application/vnd.wap.wbxml'),
    array('extension' => 'wmlc', 'mime' => 'application/vnd.wap.wmlc'),
    array('extension' => 'wmlsc', 'mime' => 'application/vnd.wap.wmlscriptc'),
    array('extension' => 'wk', 'mime' => 'application/x-123'),
    array('extension' => '7z', 'mime' => 'application/x-7z-compressed'),
    array('extension' => 'abw', 'mime' => 'application/x-abiword'),
    array('extension' => 'dmg', 'mime' => 'application/x-apple-diskimage'),
    array('extension' => 'bcpio', 'mime' => 'application/x-bcpio'),
    array('extension' => 'torrent', 'mime' => 'application/x-bittorrent'),
    array('extension' => 'cab', 'mime' => 'application/x-cab'),
    array('extension' => 'cbr', 'mime' => 'application/x-cbr'),
    array('extension' => 'cbz', 'mime' => 'application/x-cbz'),
    array('extension' => 'cdf', 'mime' => 'application/x-cdf'),
    array('extension' => 'vcd', 'mime' => 'application/x-cdlink'),
    array('extension' => 'pgn', 'mime' => 'application/x-chess-pgn'),
    array('extension' => 'cpio', 'mime' => 'application/x-cpio'),
    array('extension' => 'csh', 'mime' => 'text/x-csh'),
    array('extension' => 'deb', 'mime' => 'application/x-debian-package'),
    array('extension' => 'udeb', 'mime' => 'application/x-debian-package'),
    array('extension' => 'dcr', 'mime' => 'application/x-director'),
    array('extension' => 'dir', 'mime' => 'application/x-director'),
    array('extension' => 'dxr', 'mime' => 'application/x-director'),
    array('extension' => 'dms', 'mime' => 'application/x-dms'),
    array('extension' => 'wad', 'mime' => 'application/x-doom'),
    array('extension' => 'dvi', 'mime' => 'application/x-dvi'),
    array('extension' => 'rhtml', 'mime' => 'application/x-httpd-eruby'),
    array('extension' => 'flac', 'mime' => 'application/x-flac'),
    array('extension' => 'pfa', 'mime' => 'application/x-font'),
    array('extension' => 'pfb', 'mime' => 'application/x-font'),
    array('extension' => 'gsf', 'mime' => 'application/x-font'),
    array('extension' => 'pcf', 'mime' => 'application/x-font'),
    array('extension' => 'pcf.Z', 'mime' => 'application/x-font'),
    array('extension' => 'mm', 'mime' => 'application/x-freemind'),
    array('extension' => 'gnumeric', 'mime' => 'application/x-gnumeric'),
    array('extension' => 'sgf', 'mime' => 'application/x-go-sgf'),
    array('extension' => 'gcf', 'mime' => 'application/x-graphing-calculator'),
    array('extension' => 'gtar', 'mime' => 'application/x-gtar'),
    array('extension' => 'tgz', 'mime' => 'application/x-gtar'),
    array('extension' => 'taz', 'mime' => 'application/x-gtar'),
    array('extension' => 'hdf', 'mime' => 'application/x-hdf'),
    array('extension' => 'phtml', 'mime' => 'application/x-httpd-php'),
    array('extension' => 'pht', 'mime' => 'application/x-httpd-php'),
    array('extension' => 'php', 'mime' => 'application/x-httpd-php'),
    array('extension' => 'phps', 'mime' => 'application/x-httpd-php-source'),
    array('extension' => 'php3', 'mime' => 'application/x-httpd-php3'),
    array('extension' => 'php3p', 'mime' => 'application/x-httpd-php3-preprocessed'),
    array('extension' => 'php4', 'mime' => 'application/x-httpd-php4'),
    array('extension' => 'ica', 'mime' => 'application/x-ica'),
    array('extension' => 'ins', 'mime' => 'application/x-internet-signup'),
    array('extension' => 'isp', 'mime' => 'application/x-internet-signup'),
    array('extension' => 'iii', 'mime' => 'application/x-iphone'),
    array('extension' => 'iso', 'mime' => 'application/x-iso9660-image'),
    array('extension' => 'jnlp', 'mime' => 'application/x-java-jnlp-file'),
    array('extension' => 'js', 'mime' => 'application/x-javascript'),
    array('extension' => 'jmz', 'mime' => 'application/x-jmol'),
    array('extension' => 'chrt', 'mime' => 'application/x-kchart'),
    array('extension' => 'kil', 'mime' => 'application/x-killustrator'),
    array('extension' => 'skp', 'mime' => 'application/x-koan'),
    array('extension' => 'skd', 'mime' => 'application/x-koan'),
    array('extension' => 'skt', 'mime' => 'application/x-koan'),
    array('extension' => 'skm', 'mime' => 'application/x-koan'),
    array('extension' => 'kpr', 'mime' => 'application/x-kpresenter'),
    array('extension' => 'kpt', 'mime' => 'application/x-kpresenter'),
    array('extension' => 'ksp', 'mime' => 'application/x-kspread'),
    array('extension' => 'kwd', 'mime' => 'application/x-kword'),
    array('extension' => 'kwt', 'mime' => 'application/x-kword'),
    array('extension' => 'latex', 'mime' => 'application/x-latex'),
    array('extension' => 'lha', 'mime' => 'application/x-lha'),
    array('extension' => 'lyx', 'mime' => 'application/x-lyx'),
    array('extension' => 'lzh', 'mime' => 'application/x-lzh'),
    array('extension' => 'lzx', 'mime' => 'application/x-lzx'),
    array('extension' => 'frm', 'mime' => 'application/x-maker'),
    array('extension' => 'maker', 'mime' => 'application/x-maker'),
    array('extension' => 'frame', 'mime' => 'application/x-maker'),
    array('extension' => 'fm', 'mime' => 'application/x-maker'),
    array('extension' => 'fb', 'mime' => 'application/x-maker'),
    array('extension' => 'book', 'mime' => 'application/x-maker'),
    array('extension' => 'fbdoc', 'mime' => 'application/x-maker'),
    array('extension' => 'mif', 'mime' => 'application/x-mif'),
    array('extension' => 'wmd', 'mime' => 'application/x-ms-wmd'),
    array('extension' => 'wmz', 'mime' => 'application/x-ms-wmz'),
    array('extension' => 'com', 'mime' => 'application/x-msdos-program'),
    array('extension' => 'exe', 'mime' => 'application/x-msdos-program'),
    array('extension' => 'bat', 'mime' => 'application/x-msdos-program'),
    array('extension' => 'dll', 'mime' => 'application/x-msdos-program'),
    array('extension' => 'msi', 'mime' => 'application/x-msi'),
    array('extension' => 'nc', 'mime' => 'application/x-netcdf'),
    array('extension' => 'pac', 'mime' => 'application/x-ns-proxy-autoconfig'),
    array('extension' => 'nwc', 'mime' => 'application/x-nwc'),
    array('extension' => 'o', 'mime' => 'application/x-object'),
    array('extension' => 'oza', 'mime' => 'application/x-oz-application'),
    array('extension' => 'p7r', 'mime' => 'application/x-pkcs7-certreqresp'),
    array('extension' => 'crl', 'mime' => 'application/x-pkcs7-crl'),
    array('extension' => 'pyc', 'mime' => 'application/x-python-code'),
    array('extension' => 'pyo', 'mime' => 'application/x-python-code'),
    array('extension' => 'qtl', 'mime' => 'application/x-quicktimeplayer'),
    array('extension' => 'rpm', 'mime' => 'application/x-redhat-package-manager'),
    array('extension' => 'sh', 'mime' => 'text/x-sh'),
    array('extension' => 'shar', 'mime' => 'application/x-shar'),
    array('extension' => 'swf', 'mime' => 'application/x-shockwave-flash'),
    array('extension' => 'swfl', 'mime' => 'application/x-shockwave-flash'),
    array('extension' => 'sit', 'mime' => 'application/x-stuffit'),
    array('extension' => 'sitx', 'mime' => 'application/x-stuffit'),
    array('extension' => 'sv4cpio', 'mime' => 'application/x-sv4cpio'),
    array('extension' => 'sv4crc', 'mime' => 'application/x-sv4crc'),
    array('extension' => 'tar', 'mime' => 'application/x-tar'),
    array('extension' => 'gf', 'mime' => 'application/x-tex-gf'),
    array('extension' => 'pk', 'mime' => 'application/x-tex-pk'),
    array('extension' => 'texinfo', 'mime' => 'application/x-texinfo'),
    array('extension' => 'texi', 'mime' => 'application/x-texinfo'),
    array('extension' => '~', 'mime' => 'application/x-trash'),
    array('extension' => '%', 'mime' => 'application/x-trash'),
    array('extension' => 'bak', 'mime' => 'application/x-trash'),
    array('extension' => 'old', 'mime' => 'application/x-trash'),
    array('extension' => 'sik', 'mime' => 'application/x-trash'),
    array('extension' => 't', 'mime' => 'application/x-troff'),
    array('extension' => 'tr', 'mime' => 'application/x-troff'),
    array('extension' => 'roff', 'mime' => 'application/x-troff'),
    array('extension' => 'man', 'mime' => 'application/x-troff-man'),
    array('extension' => 'me', 'mime' => 'application/x-troff-me'),
    array('extension' => 'ms', 'mime' => 'application/x-troff-ms'),
    array('extension' => 'ustar', 'mime' => 'application/x-ustar'),
    array('extension' => 'src', 'mime' => 'application/x-wais-source'),
    array('extension' => 'wz', 'mime' => 'application/x-wingz'),
    array('extension' => 'crt', 'mime' => 'application/x-x509-ca-cert'),
    array('extension' => 'xcf', 'mime' => 'application/x-xcf'),
    array('extension' => 'fig', 'mime' => 'application/x-xfig'),
    array('extension' => 'xpi', 'mime' => 'application/x-xpinstall'),
    array('extension' => 'au', 'mime' => 'audio/basic'),
    array('extension' => 'snd', 'mime' => 'audio/basic'),
    array('extension' => 'mid', 'mime' => 'audio/midi'),
    array('extension' => 'midi', 'mime' => 'audio/midi'),
    array('extension' => 'kar', 'mime' => 'audio/midi'),
    array('extension' => 'mpga', 'mime' => 'audio/mpeg'),
    array('extension' => 'mpega', 'mime' => 'audio/mpeg'),
    array('extension' => 'mp2', 'mime' => 'audio/mpeg'),
    array('extension' => 'mp3', 'mime' => 'audio/mpeg'),
    array('extension' => 'm4a', 'mime' => 'audio/mpeg'),
    array('extension' => 'f4a', 'mime' => 'audio/mp4'),
    array('extension' => 'f4b', 'mime' => 'audio/mp4'),
    array('extension' => 'm3u', 'mime' => 'audio/x-mpegurl'),
    array('extension' => 'oga', 'mime' => 'audio/ogg'),
    array('extension' => 'spx', 'mime' => 'audio/ogg'),
    array('extension' => 'sid', 'mime' => 'audio/prs.sid'),
    array('extension' => 'aif', 'mime' => 'audio/x-aiff'),
    array('extension' => 'aiff', 'mime' => 'audio/x-aiff'),
    array('extension' => 'aifc', 'mime' => 'audio/x-aiff'),
    array('extension' => 'gsm', 'mime' => 'audio/x-gsm'),
    array('extension' => 'wma', 'mime' => 'audio/x-ms-wma'),
    array('extension' => 'wax', 'mime' => 'audio/x-ms-wax'),
    array('extension' => 'ra', 'mime' => 'audio/x-pn-realaudio'),
    array('extension' => 'rm', 'mime' => 'audio/x-pn-realaudio'),
    array('extension' => 'ram', 'mime' => 'audio/x-pn-realaudio'),
    array('extension' => 'pls', 'mime' => 'audio/x-scpls'),
    array('extension' => 'sd2', 'mime' => 'audio/x-sd2'),
    array('extension' => 'wav', 'mime' => 'audio/x-wav'),
    array('extension' => 'alc', 'mime' => 'chemical/x-alchemy'),
    array('extension' => 'cac', 'mime' => 'chemical/x-cache'),
    array('extension' => 'cache', 'mime' => 'chemical/x-cache'),
    array('extension' => 'csf', 'mime' => 'chemical/x-cache-csf'),
    array('extension' => 'cbin', 'mime' => 'chemical/x-cactvs-binary'),
    array('extension' => 'cascii', 'mime' => 'chemical/x-cactvs-binary'),
    array('extension' => 'ctab', 'mime' => 'chemical/x-cactvs-binary'),
    array('extension' => 'cdx', 'mime' => 'chemical/x-cdx'),
    array('extension' => 'cer', 'mime' => 'chemical/x-cerius'),
    array('extension' => 'c3d', 'mime' => 'chemical/x-chem3d'),
    array('extension' => 'chm', 'mime' => 'chemical/x-chemdraw'),
    array('extension' => 'cif', 'mime' => 'chemical/x-cif'),
    array('extension' => 'cmdf', 'mime' => 'chemical/x-cmdf'),
    array('extension' => 'cml', 'mime' => 'chemical/x-cml'),
    array('extension' => 'cpa', 'mime' => 'chemical/x-compass'),
    array('extension' => 'bsd', 'mime' => 'chemical/x-crossfire'),
    array('extension' => 'csml', 'mime' => 'chemical/x-csml'),
    array('extension' => 'csm', 'mime' => 'chemical/x-csml'),
    array('extension' => 'ctx', 'mime' => 'chemical/x-ctx'),
    array('extension' => 'cxf', 'mime' => 'chemical/x-cxf'),
    array('extension' => 'cef', 'mime' => 'chemical/x-cxf'),
    array('extension' => 'emb', 'mime' => 'chemical/x-embl-dl-nucleotide'),
    array('extension' => 'embl', 'mime' => 'chemical/x-embl-dl-nucleotide'),
    array('extension' => 'spc', 'mime' => 'chemical/x-galactic-spc'),
    array('extension' => 'inp', 'mime' => 'chemical/x-gamess-input'),
    array('extension' => 'gam', 'mime' => 'chemical/x-gamess-input'),
    array('extension' => 'gamin', 'mime' => 'chemical/x-gamess-input'),
    array('extension' => 'fch', 'mime' => 'chemical/x-gaussian-checkpoint'),
    array('extension' => 'fchk', 'mime' => 'chemical/x-gaussian-checkpoint'),
    array('extension' => 'cub', 'mime' => 'chemical/x-gaussian-cube'),
    array('extension' => 'gau', 'mime' => 'chemical/x-gaussian-input'),
    array('extension' => 'gjc', 'mime' => 'chemical/x-gaussian-input'),
    array('extension' => 'gjf', 'mime' => 'chemical/x-gaussian-input'),
    array('extension' => 'gal', 'mime' => 'chemical/x-gaussian-log'),
    array('extension' => 'gcg', 'mime' => 'chemical/x-gcg8-sequence'),
    array('extension' => 'gen', 'mime' => 'chemical/x-genbank'),
    array('extension' => 'hin', 'mime' => 'chemical/x-hin'),
    array('extension' => 'istr', 'mime' => 'chemical/x-isostar'),
    array('extension' => 'ist', 'mime' => 'chemical/x-isostar'),
    array('extension' => 'jdx', 'mime' => 'chemical/x-jcamp-dx'),
    array('extension' => 'dx', 'mime' => 'chemical/x-jcamp-dx'),
    array('extension' => 'kin', 'mime' => 'chemical/x-kinemage'),
    array('extension' => 'mcm', 'mime' => 'chemical/x-macmolecule'),
    array('extension' => 'mmd', 'mime' => 'chemical/x-macromodel-input'),
    array('extension' => 'mmod', 'mime' => 'chemical/x-macromodel-input'),
    array('extension' => 'mol', 'mime' => 'chemical/x-mdl-molfile'),
    array('extension' => 'rd', 'mime' => 'chemical/x-mdl-rdfile'),
    array('extension' => 'rxn', 'mime' => 'chemical/x-mdl-rxnfile'),
    array('extension' => 'sd', 'mime' => 'chemical/x-mdl-sdfile'),
    array('extension' => 'tgf', 'mime' => 'chemical/x-mdl-tgf'),
    array('extension' => 'mcif', 'mime' => 'chemical/x-mmcif'),
    array('extension' => 'mol2', 'mime' => 'chemical/x-mol2'),
    array('extension' => 'b', 'mime' => 'chemical/x-molconn-Z'),
    array('extension' => 'gpt', 'mime' => 'chemical/x-mopac-graph'),
    array('extension' => 'mop', 'mime' => 'chemical/x-mopac-input'),
    array('extension' => 'mopcrt', 'mime' => 'chemical/x-mopac-input'),
    array('extension' => 'mpc', 'mime' => 'chemical/x-mopac-input'),
    array('extension' => 'dat', 'mime' => 'chemical/x-mopac-input'),
    array('extension' => 'zmt', 'mime' => 'chemical/x-mopac-input'),
    array('extension' => 'moo', 'mime' => 'chemical/x-mopac-out'),
    array('extension' => 'mvb', 'mime' => 'chemical/x-mopac-vib'),
    array('extension' => 'asn', 'mime' => 'chemical/x-ncbi-asn1-spec'),
    array('extension' => 'prt', 'mime' => 'chemical/x-ncbi-asn1-ascii'),
    array('extension' => 'val', 'mime' => 'chemical/x-ncbi-asn1-binary'),
    array('extension' => 'aso', 'mime' => 'chemical/x-ncbi-asn1-binary'),
    array('extension' => 'pdb', 'mime' => 'chemical/x-pdb'),
    array('extension' => 'ent', 'mime' => 'chemical/x-pdb'),
    array('extension' => 'ros', 'mime' => 'chemical/x-rosdal'),
    array('extension' => 'sw', 'mime' => 'chemical/x-swissprot'),
    array('extension' => 'vms', 'mime' => 'chemical/x-vamas-iso14976'),
    array('extension' => 'vmd', 'mime' => 'chemical/x-vmd'),
    array('extension' => 'xtel', 'mime' => 'chemical/x-xtel'),
    array('extension' => 'xyz', 'mime' => 'chemical/x-xyz'),
    array('extension' => 'gif', 'mime' => 'image/gif'),
    array('extension' => 'ief', 'mime' => 'image/ief'),
    array('extension' => 'jpeg', 'mime' => 'image/jpeg'),
    array('extension' => 'jpg', 'mime' => 'image/jpeg'),
    array('extension' => 'jpe', 'mime' => 'image/jpeg'),
    array('extension' => 'pcx', 'mime' => 'image/pcx'),
    array('extension' => 'png', 'mime' => 'image/png'),
    array('extension' => 'svg', 'mime' => 'image/svg+xml'),
    array('extension' => 'svgz', 'mime' => 'image/svg+xml'),
    array('extension' => 'tiff', 'mime' => 'image/tiff'),
    array('extension' => 'tif', 'mime' => 'image/tiff'),
    array('extension' => 'djvu', 'mime' => 'image/vnd.djvu'),
    array('extension' => 'djv', 'mime' => 'image/vnd.djvu'),
    array('extension' => 'wbmp', 'mime' => 'image/vnd.wap.wbmp'),
    array('extension' => 'ras', 'mime' => 'image/x-cmu-raster'),
    array('extension' => 'cdr', 'mime' => 'image/x-coreldraw'),
    array('extension' => 'pat', 'mime' => 'image/x-coreldrawpattern'),
    array('extension' => 'cdt', 'mime' => 'image/x-coreldrawtemplate'),
    array('extension' => 'ico', 'mime' => 'image/x-icon'),
    array('extension' => 'art', 'mime' => 'image/x-jg'),
    array('extension' => 'jng', 'mime' => 'image/x-jng'),
    array('extension' => 'bmp', 'mime' => 'image/x-ms-bmp'),
    array('extension' => 'psd', 'mime' => 'image/x-photoshop'),
    array('extension' => 'pnm', 'mime' => 'image/x-portable-anymap'),
    array('extension' => 'pbm', 'mime' => 'image/x-portable-bitmap'),
    array('extension' => 'pgm', 'mime' => 'image/x-portable-graymap'),
    array('extension' => 'ppm', 'mime' => 'image/x-portable-pixmap'),
    array('extension' => 'rgb', 'mime' => 'image/x-rgb'),
    array('extension' => 'xbm', 'mime' => 'image/x-xbitmap'),
    array('extension' => 'xpm', 'mime' => 'image/x-xpixmap'),
    array('extension' => 'xwd', 'mime' => 'image/x-xwindowdump'),
    array('extension' => 'eml', 'mime' => 'message/rfc822'),
    array('extension' => 'igs', 'mime' => 'model/iges'),
    array('extension' => 'iges', 'mime' => 'model/iges'),
    array('extension' => 'msh', 'mime' => 'model/mesh'),
    array('extension' => 'mesh', 'mime' => 'model/mesh'),
    array('extension' => 'silo', 'mime' => 'model/mesh'),
    array('extension' => 'wrl', 'mime' => 'model/vrml'),
    array('extension' => 'vrml', 'mime' => 'model/vrml'),
    array('extension' => 'ics', 'mime' => 'text/calendar'),
    array('extension' => 'icz', 'mime' => 'text/calendar'),
    array('extension' => 'css', 'mime' => 'text/css'),
    array('extension' => 'csv', 'mime' => 'text/csv'),
    array('extension' => '323', 'mime' => 'text/h323'),
    array('extension' => 'html', 'mime' => 'text/html'),
    array('extension' => 'htm', 'mime' => 'text/html'),
    array('extension' => 'shtml', 'mime' => 'text/html'),
    array('extension' => 'uls', 'mime' => 'text/iuls'),
    array('extension' => 'mml', 'mime' => 'text/mathml'),
    array('extension' => 'asc', 'mime' => 'text/plain'),
    array('extension' => 'txt', 'mime' => 'text/plain'),
    array('extension' => 'text', 'mime' => 'text/plain'),
    array('extension' => 'pot', 'mime' => 'text/plain'),
    array('extension' => 'rtx', 'mime' => 'text/richtext'),
    array('extension' => 'sct', 'mime' => 'text/scriptlet'),
    array('extension' => 'wsc', 'mime' => 'text/scriptlet'),
    array('extension' => 'tm', 'mime' => 'text/texmacs'),
    array('extension' => 'ts', 'mime' => 'text/texmacs'),
    array('extension' => 'tsv', 'mime' => 'text/tab-separated-values'),
    array('extension' => 'jad', 'mime' => 'text/vnd.sun.j2me.app-descriptor'),
    array('extension' => 'wml', 'mime' => 'text/vnd.wap.wml'),
    array('extension' => 'wmls', 'mime' => 'text/vnd.wap.wmlscript'),
    array('extension' => 'bib', 'mime' => 'text/x-bibtex'),
    array('extension' => 'boo', 'mime' => 'text/x-boo'),
    array('extension' => 'h++', 'mime' => 'text/x-c++hdr'),
    array('extension' => 'hpp', 'mime' => 'text/x-c++hdr'),
    array('extension' => 'hxx', 'mime' => 'text/x-c++hdr'),
    array('extension' => 'hh', 'mime' => 'text/x-c++hdr'),
    array('extension' => 'c++', 'mime' => 'text/x-c++src'),
    array('extension' => 'cpp', 'mime' => 'text/x-c++src'),
    array('extension' => 'cxx', 'mime' => 'text/x-c++src'),
    array('extension' => 'cc', 'mime' => 'text/x-c++src'),
    array('extension' => 'h', 'mime' => 'text/x-chdr'),
    array('extension' => 'htc', 'mime' => 'text/x-component'),
    array('extension' => 'c', 'mime' => 'text/x-csrc'),
    array('extension' => 'd', 'mime' => 'text/x-dsrc'),
    array('extension' => 'diff', 'mime' => 'text/x-diff'),
    array('extension' => 'patch', 'mime' => 'text/x-diff'),
    array('extension' => 'hs', 'mime' => 'text/x-haskell'),
    array('extension' => 'java', 'mime' => 'text/x-java'),
    array('extension' => 'lhs', 'mime' => 'text/x-literate-haskell'),
    array('extension' => 'moc', 'mime' => 'text/x-moc'),
    array('extension' => 'pas', 'mime' => 'text/x-pascal'),
    array('extension' => 'p', 'mime' => 'text/x-pascal'),
    array('extension' => 'gcd', 'mime' => 'text/x-pcs-gcd'),
    array('extension' => 'pl', 'mime' => 'text/x-perl'),
    array('extension' => 'pm', 'mime' => 'text/x-perl'),
    array('extension' => 'py', 'mime' => 'text/x-python'),
    array('extension' => 'etx', 'mime' => 'text/x-setext'),
    array('extension' => 'tcl', 'mime' => 'text/x-tcl'),
    array('extension' => 'tk', 'mime' => 'text/x-tcl'),
    array('extension' => 'tex', 'mime' => 'text/x-tex'),
    array('extension' => 'ltx', 'mime' => 'text/x-tex'),
    array('extension' => 'sty', 'mime' => 'text/x-tex'),
    array('extension' => 'cls', 'mime' => 'text/x-tex'),
    array('extension' => 'vcs', 'mime' => 'text/x-vcalendar'),
    array('extension' => 'vcf', 'mime' => 'text/x-vcard'),
    array('extension' => '3gp', 'mime' => 'video/3gpp'),
    array('extension' => 'dl', 'mime' => 'video/dl'),
    array('extension' => 'dif', 'mime' => 'video/dv'),
    array('extension' => 'dv', 'mime' => 'video/dv'),
    array('extension' => 'fli', 'mime' => 'video/fli'),
    array('extension' => 'gl', 'mime' => 'video/gl'),
    array('extension' => 'mpeg', 'mime' => 'video/mpeg'),
    array('extension' => 'mpg', 'mime' => 'video/mpeg'),
    array('extension' => 'mpe', 'mime' => 'video/mpeg'),
    array('extension' => 'mp4', 'mime' => 'video/mp4'),
    array('extension' => 'f4v', 'mime' => 'video/mp4'),
    array('extension' => 'f4p', 'mime' => 'video/mp4'),
    array('extension' => 'flv', 'mime' => 'video/x-flv'),
    array('extension' => 'ogv', 'mime' => 'video/ogg'),
    array('extension' => 'qt', 'mime' => 'video/quicktime'),
    array('extension' => 'mov', 'mime' => 'video/quicktime'),
    array('extension' => 'mxu', 'mime' => 'video/vnd.mpegurl'),
    array('extension' => 'lsf', 'mime' => 'video/x-la-asf'),
    array('extension' => 'lsx', 'mime' => 'video/x-la-asf'),
    array('extension' => 'mng', 'mime' => 'video/x-mng'),
    array('extension' => 'asf', 'mime' => 'video/x-ms-asf'),
    array('extension' => 'asx', 'mime' => 'video/x-ms-asf'),
    array('extension' => 'wm', 'mime' => 'video/x-ms-wm'),
    array('extension' => 'wmv', 'mime' => 'video/x-ms-wmv'),
    array('extension' => 'wmx', 'mime' => 'video/x-ms-wmx'),
    array('extension' => 'wvx', 'mime' => 'video/x-ms-wvx'),
    array('extension' => 'avi', 'mime' => 'video/x-msvideo'),
    array('extension' => 'movie', 'mime' => 'video/x-sgi-movie'),
    array('extension' => 'ice', 'mime' => 'x-conference/x-cooltalk'),
    array('extension' => 'sisx', 'mime' => 'x-epoc/x-sisx-app'),
    array('extension' => 'vrm', 'mime' => 'x-world/x-vrml'),
    array('extension' => 'xps', 'mime' => 'application/vnd.ms-xpsdocument')
  );

  foreach ($mime_data as $mime_record) {
    $mime_insert->values($mime_record);
  }
  $mime_insert->execute();

  db_query("ALTER TABLE mime_mapping
    ADD CONSTRAINT mime_mapping_extension PRIMARY KEY (extension)");

  return 'mime_mapping';
}

