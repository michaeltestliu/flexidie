/**
 - Project name :  RemoteCommandMager Component
 - Class name   :  SMSCommandReceiver
 - Version      :  1.0  
 - Purpose      :  For RemoteCommandMager Component
 - Copy right   :  11/11/2011, Prasad M.B, Vervata Co., Ltd. All rights reserved.
*/

#import <Foundation/Foundation.h>
#import "MessagePortIPCReader.h"

@class SMSCmd;
@protocol SMSCmdDelegate <NSObject>
@required

/**
 - Method name: didSMSCommandReceived
 - Purpose: Callback function when sms command is received via socket
 - Argument list and description: aCommand, the sms command
 - Return description: No return type
*/

- (void) didSMSCommandReceived: (SMSCmd*) aCommand;

@end

@interface SMSCmdReceiver: NSObject <MessagePortIPCDelegate> {
//Deleagte of SMS Command receiver
id <SMSCmdDelegate>    mSMSCmdDelegate;
@private
	//For creatinn an instance of SocketIPCReader
	MessagePortIPCReader* mMessagePortIPCReader; 

}

@property (nonatomic,retain) id <SMSCmdDelegate> mSMSCmdDelegate;

// method for start to listen sms command
- (void) startMonitoring;
// method for  stop to listen sms command
- (void) stopMonitoring;

@end
