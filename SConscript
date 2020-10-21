Import('*')

sources = []

targetEnv.RegisterModule('esp_at_lib', depend=['kernel'])
sources.extend(File(Split("""
	lwesp/src/api/lwesp_netconn.c
	
	lwesp/src/cli/cli.c
	lwesp/src/cli/cli_input.c
	
	
	lwesp/src/lwesp/lwesp.c
	lwesp/src/lwesp/lwesp_ap.c
	lwesp/src/lwesp/lwesp_buff.c
	lwesp/src/lwesp/lwesp_cli.c
	lwesp/src/lwesp/lwesp_conn.c
	lwesp/src/lwesp/lwesp_debug.c
	lwesp/src/lwesp/lwesp_dhcp.c
	lwesp/src/lwesp/lwesp_dns.c
	lwesp/src/lwesp/lwesp_evt.c
	lwesp/src/lwesp/lwesp_hostname.c
	lwesp/src/lwesp/lwesp_input.c
	lwesp/src/lwesp/lwesp_int.c
	lwesp/src/lwesp/lwesp_mem.c
	lwesp/src/lwesp/lwesp_parser.c
	lwesp/src/lwesp/lwesp_pbuf.c
	lwesp/src/lwesp/lwesp_ping.c
	lwesp/src/lwesp/lwesp_smart.c
	lwesp/src/lwesp/lwesp_sta.c
	lwesp/src/lwesp/lwesp_threads.c
	lwesp/src/lwesp/lwesp_timeout.c
	lwesp/src/lwesp/lwesp_unicode.c
	lwesp/src/lwesp/lwesp_utils.c
	lwesp/src/lwesp/lwesp_wps.c
	
	
	lwesp/src/system/lwesp_ll_stm32.c
	lwesp/src/system/lwesp_mem_lwmem.c
	lwesp/src/system/lwesp_sys_cmsis_os.c
	
""")))

# use libraries http server
if 1:
	sources.extend(File(Split("""
		lwesp/src/apps/http_server/lwesp_http_server.c
		lwesp/src/apps/http_server/lwesp_http_server_fs.c
		lwesp/src/apps/http_server/lwesp_http_server_fs_fat.c
	""")))

# use libraries mqtt client
if 1:
	sources.extend(File(Split("""
		lwesp/src/apps/mqtt/lwesp_mqtt_client.c
		lwesp/src/apps/mqtt/lwesp_mqtt_client_api.c
		lwesp/src/apps/mqtt/lwesp_mqtt_client_evt.c
	""")))

targetEnv.AppendUnique(
	CPPPATH=[
		Dir('lwesp/src/include/'),
		Dir('lwesp/src/include/system/port/cmsis_os/'),
	]
)

program_sources.extend(sources)
program_objects.extend(targetEnv.StaticObject(sources))

