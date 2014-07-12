#require('./media-accel')

StructHelpers = require('./StructHelpers')

defUI1 = (cls, name, byteNum, bitNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf[byteNum]=setbv @buf[byteNum], bitNum, v
	cls.prototype.__defineGetter__ name, -> getb @buf[byteNum], bitNum
	return

defUI8 = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf[byteNum]=v
	cls.prototype.__defineGetter__ name, -> @buf[byteNum]
	return

defUI16BE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.writeUInt16BE v, byteNum
	cls.prototype.__defineGetter__ name, -> @buf.readUInt16BE byteNum
	return

defUI16LE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.writeUInt16LE v, byteNum
	cls.prototype.__defineGetter__ name, -> @buf.readUInt16LE byteNum
	return

defI16LE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.writeInt16LE v, byteNum
	cls.prototype.__defineGetter__ name, -> @buf.readInt16LE byteNum
	return

defUI24BE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf[byteNum]=v >>> 16; @buf[byteNum+1]=v >>> 8; @buf[byteNum+2]=v
	cls.prototype.__defineGetter__ name, -> (@buf[byteNum]<<16) + (@buf[byteNum+1]<<8) + (@buf[byteNum+2])
	return

defUI32BE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.writeUInt32BE v, byteNum
	cls.prototype.__defineGetter__ name, -> @buf.readUInt32BE byteNum
	return

defUI32LE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.writeUInt32LE v, byteNum
	cls.prototype.__defineGetter__ name, -> @buf.readUInt32LE byteNum
	return

defI32LE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.writeInt32LE v, byteNum
	cls.prototype.__defineGetter__ name, -> @buf.readInt32LE byteNum
	return

defUI64LE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) ->
		@buf.writeUInt32LE v >>> 0, byteNum
		@buf.writeUInt32LE (v * Math.pow(2, -32)) >>> 0, byteNum + 4
	cls.prototype.__defineGetter__ name, ->
		@buf.readUInt32LE(byteNum) + @buf.readUInt32LE(byteNum + 4) * Math.pow(2, -32)
	return

defI64LE = (cls, name, byteNum)->
	cls.prototype.__defineSetter__ name, (v) ->
		@buf.writeUInt32LE v >>> 0, byteNum
		@buf.writeUInt32LE (v * Math.pow(2, -32)) >>> 0, byteNum + 4
	cls.prototype.__defineGetter__ name, ->
		@buf.readUInt32LE(byteNum) + @buf.readUInt32LE(byteNum + 4) * Math.pow(2, -32)
	return

readCString = (buf)->
	for n, i in buf
		unless n
			return buf.toString 'utf8', 0, i
	return buf.toString 'utf8'

defUTF8 = (cls, name, byteNum, byteCount)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.write v, byteNum, byteCount
	cls.prototype.__defineGetter__ name, -> readCString(@buf.slice(byteNum, byteNum + byteCount)) #@buf.toString byteNum, byteNum + byteCount
	return

defASCII = (cls, name, byteNum, byteCount)->
	cls.prototype.__defineSetter__ name, (v) -> @buf.write v, byteNum, byteCount, 'ascii'
	cls.prototype.__defineGetter__ name, -> @buf.toString 'ascii', byteNum, byteNum + byteCount
	return

deftoString = (cls)->
	Object.defineProperty cls.prototype, 'toString',
		value: ->
			sto={}
			for k of cls.prototype
				sto[k] = @[k]
				sto[k] = sto[k].toString 'hex' if Buffer.isBuffer sto[k]
			#JSON.stringify sto, undefined, ' '
			sto

debugStructs = false

exports.def_pack_std = (dst, obj)->
	if debugStructs then console.log 'exports.def_pack_std', arguments
	StructHelpers.addStandardFunctions dst
	byteNum = 0
	for k, t of obj
		switch t
			when 'int32_t', 'int', 'INT', 'LONG'
				byteNum++ while byteNum & 3
				defI32LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 4

			when 'uint8_t', 'uchar', 'UCHAR', 'BYTE'
				defUI8 dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 1

			when 'uint16_t', 'ushort', 'USHORT', 'WORD'
				byteNum++ while byteNum & 1
				defUI16LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 2

			when 'uint32_t', 'uint', 'UINT', 'DWORD'
				byteNum++ while byteNum & 3
				defUI32LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 4

			when 'uint64_t', 'UINT_PTR', 'WPARAM'
				byteNum++ while byteNum & 7
				defUI64LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 8

			when 'int64_t', 'INT_PTR', 'LPARAM'
				byteNum++ while byteNum & 7
				defI64LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 8

			when 'WNDPROC'
				byteNum++ while byteNum & 7
				defI64LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 8

			when 'HWND', 'HANDLE', 'HINSTANCE', 'HICON', 'HCURSOR', 'HBRUSH'
				byteNum++ while byteNum & 7
				defI64LE dst, k, byteNum
				if debugStructs then console.log k, t, byteNum
				byteNum += 8

			when 'LPCWSTR'
				byteNum++ while byteNum & 7
				if debugStructs then console.log k, t, byteNum
				do(byteNum)->
					Object.defineProperty dst.prototype, '_buf_' + k,
						value: undefined
						writable: true
						enumerable: false
						configurable : false

					dst.prototype.__defineSetter__ k, (v) ->
						@['_buf' + k] = new Buffer(v, 'utf16le')
						#storeBufferPointer(
						@buf.writeUInt32LE v, byteNum
						@buf.writeUInt32LE v * Math.pow(2, -32), byteNum + 4

					dst.prototype.__defineGetter__ k, ->
						@buf.readUInt32LE(byteNum) + @buf.readUInt32LE(byteNum + 4) * Math.pow(2, -32)

				byteNum += 8

			else
				console.log k: t
	if debugStructs then console.log 'final size: ', byteNum

exports.MSG = (dbuf)->
	unless @ instanceof exports.MSG
		switch arguments.length
			when 1 then return new exports.MSG(arguments[0])
			else        return new exports.MSG()

	if Buffer.isBuffer dbuf
		dbuf = dbuf.slice 0, 48
	else
		dbuf = new Buffer 48
		dbuf.fill 0

	Object.defineProperty(@, 'buf', {value: dbuf, writable: true, enumerable: false, configurable : false});
	return @

exports.def_pack_std exports.MSG,
	hwnd:    'HWND'   # 0   0
	message: 'UINT'   # 8   8
	wParam:  'WPARAM' #12  16
	lParam:  'LPARAM' #20  24
	time:    'DWORD'  #28  32
	ptX:     'LONG'   #32  36
	ptY:     'LONG'   #36  40
#40

exports.MSG.prototype.toString = ->
	sto={}
	for k of exports.MSG.prototype
		sto[k] = @[k]
		sto[k] = sto[k].toString 'hex' if Buffer.isBuffer sto[k]
	JSON.stringify sto, undefined, ' '


StructHelpers.add_fromObjects exports.MSG

exports.createClass = (name, bufSize, obj) ->
	ret = (dbuf)->
		unless @ instanceof ret
			switch arguments.length
				when 1 then return new ret(arguments[0])
				else        return new ret()
	
		if Buffer.isBuffer dbuf
			dbuf = dbuf.slice 0, bufSize
		else
			dbuf = new Buffer bufSize
			dbuf.fill 0
	
		Object.defineProperty(@, 'buf', {value: dbuf, writable: true, enumerable: false, configurable : false});
		return @
	exports.def_pack_std ret, obj
	return ret


if debugStructs then console.log 'PIXELFORMATDESCRIPTOR', User32.sizeof_PIXELFORMATDESCRIPTOR

exports.PIXELFORMATDESCRIPTOR = exports.createClass 'PIXELFORMATDESCRIPTOR', User32.sizeof_PIXELFORMATDESCRIPTOR, 
	nSize:             'WORD'
	nVersion:          'WORD'
	dwFlags:           'DWORD'
	iPixelType:        'BYTE'
	cColorBits:        'BYTE'
	cRedBits:          'BYTE'
	cRedShift:         'BYTE'
	cGreenBits:        'BYTE'
	cGreenShift:       'BYTE'
	cBlueBits:         'BYTE'
	cBlueShift:        'BYTE'
	cAlphaBits:        'BYTE'
	cAlphaShift:       'BYTE'
	cAccumBits:        'BYTE'
	cAccumRedBits:     'BYTE'
	cAccumGreenBits:   'BYTE'
	cAccumBlueBits:    'BYTE'
	cAccumAlphaBits:   'BYTE'
	cDepthBits:        'BYTE'
	cStencilBits:      'BYTE'
	cAuxBuffers:       'BYTE'
	iLayerType:        'BYTE'
	bReserved:         'BYTE'
	dwLayerMask:       'DWORD'
	dwVisibleMask:     'DWORD'
	dwDamageMask:      'DWORD'


if false
	pf = new exports.PIXELFORMATDESCRIPTOR()
	console.log 'pf', pf
	console.log 'pf.toObject', pf.toObject
	console.log 'pf.toString', pf.toString
	console.log 'pf.toObject()', pf.toObject()
	console.log 'pf.toString()', pf.toString()
	#console.log exports.PIXELFORMATDESCRIPTOR.prototype.toString
	
	pfo = exports.PIXELFORMATDESCRIPTOR.fromObjects
		nSize: 40
	
	console.log 'pfo: ', pfo.toObject()
	console.log 'pfo.buf: ', pfo.buf.length, pfo.buf
	
#defI32LE exports.RECT, 'left', 0
#defI32LE exports.RECT, 'top', 4
#defI32LE exports.RECT, 'right', 8
#defI32LE exports.RECT, 'bottom', 12

exports.RECT = exports.createClass 'RECT', User32.sizeof_RECT,
	left:   'LONG'
	top:    'LONG'
	right:  'LONG'
	bottom: 'LONG'
