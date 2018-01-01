function varargout = luyinji(varargin)
% LUYINJI MATLAB code for luyinji.fig
%      LUYINJI, by itself, creates a new LUYINJI or raises the existing
%      singleton*.
%
%      H = LUYINJI returns the handle to a new LUYINJI or the handle to
%      the existing singleton*.
%
%      LUYINJI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LUYINJI.M with the given input arguments.
%
%      LUYINJI('Property','Value',...) creates a new LUYINJI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before luyinji_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to luyinji_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help luyinji

% Last Modified by GUIDE v2.5 02-Dec-2016 19:53:28

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @luyinji_OpeningFcn, ...
                   'gui_OutputFcn',  @luyinji_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before luyinji is made visible.
function luyinji_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to luyinji (see VARARGIN)

% Choose default command line output for luyinji
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes luyinji wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = luyinji_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global signal;
h = waitbar(0,' Recording .... ');
Fs=10000;
for i=1:1
    data=wavrecord(5*Fs,Fs);  % 5 seconds recording
    waitbar(i/1,h)
end
close (h);
signal=data;


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global signal;
Fs=10000;
signal = 0.99*signal/max(abs(signal));
if length(signal) ~= 0
      wavplay(signal,Fs)
end



% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global signal;
Fs = 10000;
[filename, pathname] = uiputfile('*.wav', 'save data as .wav file');
    if filename ~= 0
  wavwrite(signal,Fs,[pathname filename])
    end
