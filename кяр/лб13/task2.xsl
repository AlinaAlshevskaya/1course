<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head><title>My first template rule</title>
</head>
<body>
<table border="1">
<tr bgcolor="#9acd32">
<th>Имя</th>
<th>Оценка</th></tr>
<xsl:for-each select="list/product">
<xsl:sort select="nameproduct"/>
<tr>
<td><xsl:value-of select="nameproduct"/></td>
<xsl:choose>
<xsl:when test="description &gt;8">
<td bgcolor="green">
<xsl:value-of select="description"/></td>
</xsl:when>
<xsl:when test="description &lt;4">
<td bgcolor="red">
<xsl:value-of select="description"/></td>
</xsl:when>
<xsl:otherwise>
<td><xsl:value-of select="description"/></td>
</xsl:otherwise>
</xsl:choose>
</tr>
</xsl:for-each>
</table></body></html>
</xsl:template>
</xsl:stylesheet>
