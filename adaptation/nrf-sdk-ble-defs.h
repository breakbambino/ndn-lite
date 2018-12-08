
#ifndef NRF_SDK_BLE_DEFS_H
#define NRF_SDK_BLE_DEFS_H

// a uuid arbitrarily defined for advertising, so that the ble face scanner doesn't detect 
// advertisements that aren't generated by an ndn-lite ble face
#define NDN_LITE_BLE_EXT_ADV_UUID 0x6593

/**@brief UUIDs that the central application scans for if the name above is set to an empty string,
 * and that are to be advertised by the peripherals.
 */
static ble_uuid_t m_adv_uuids[] =
{
    {NDN_LITE_BLE_EXT_ADV_UUID,        BLE_UUID_TYPE_BLE},
};

// the code below was adapted from this example: https://devzone.nordicsemi.com/f/nordic-q-a/37604/extended-advertising-scannable

#define DEVICE_NAME                     ""                                         /**< Name of device used for advertising. */
#define MANUFACTURER_NAME               "NordicSemiconductor"                       /**< Manufacturer. Passed to Device Information Service. */
#define APP_ADV_INTERVAL                1600                                        /**< The advertising interval (in units of 0.625 ms). This value corresponds to 187.5 ms. */

#define APP_ADV_DURATION                180                                          /**< The advertising duration (180 seconds) in units of 10 milliseconds. */

#define APP_BLE_CONN_CFG_TAG            1                                           /**< Tag that identifies the SoftDevice BLE configuration. */

#define FIRST_CONN_PARAMS_UPDATE_DELAY  APP_TIMER_TICKS(5000)                       /**< Time from initiating event (connect or start of notification) to the first time sd_ble_gap_conn_param_update is called (5 seconds). */
#define NEXT_CONN_PARAMS_UPDATE_DELAY   APP_TIMER_TICKS(30000)                      /**< Time between each call to sd_ble_gap_conn_param_update after the first call (30 seconds). */
#define MAX_CONN_PARAMS_UPDATE_COUNT    3                                           /**< Number of attempts before giving up the connection parameter negotiation. */

#define SEC_PARAM_BOND                  1                                           /**< Perform bonding. */
#define SEC_PARAM_MITM                  0                                           /**< Man In The Middle protection not required. */
#define SEC_PARAM_LESC                  0                                           /**< LE Secure Connections not enabled. */
#define SEC_PARAM_KEYPRESS              0                                           /**< Keypress notifications not enabled. */
#define SEC_PARAM_IO_CAPABILITIES       BLE_GAP_IO_CAPS_NONE                        /**< No I/O capabilities. */
#define SEC_PARAM_OOB                   0                                           /**< Out Of Band data not available. */
#define SEC_PARAM_MIN_KEY_SIZE          7                                           /**< Minimum encryption key size in octets. */
#define SEC_PARAM_MAX_KEY_SIZE          16                                          /**< Maximum encryption key size in octets. */

#define HART_RATE_SERVICE_UUID_IDX      0                                           /**< Hart Rate service UUID index in array. */
#define RSCS_SERVICE_UUID_IDX           1                                           /**< RSCS service UUID index in array. */

/**@brief   Priority of the application BLE event handler.
 * @note    You shouldn't need to modify this value.
 */
#define APP_BLE_OBSERVER_PRIO           3

BLE_ADVERTISING_DEF(m_advertising);                                 /**< Advertising module instance. */
NRF_BLE_SCAN_DEF(m_scan);                                           /**< Scanning module instance. */

static ble_gap_scan_params_t m_scan_param = /**< Scan parameters requested for scanning and connection. */
    {
        .active = 0x00,
        .interval = NRF_BLE_SCAN_SCAN_INTERVAL,
        .window = NRF_BLE_SCAN_SCAN_WINDOW,
        .filter_policy = BLE_GAP_SCAN_FP_ACCEPT_ALL,
        .timeout = NRF_BLE_SCAN_SCAN_DURATION,
        .scan_phys = BLE_GAP_PHY_1MBPS,
        .extended = 1,
};

#endif // NRF_SDK_BLE_DEFS_H