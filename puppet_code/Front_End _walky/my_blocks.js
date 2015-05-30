

Blockly.Blocks['prop_serial_print'] = {
  init: function() {
    this.setHelpUrl("https://propsideworkspace.googlecode.com/hg-history/029efb9bf270758003c0a67571d1cbe4cc9986b5/Learn/Simple%20Libraries/Utility/libsimpletools/Documentation%20simpletools%20Library.html");
    this.setColour(160);
    this.appendValueInput("TEXT")
		.appendField("Serial_print")
        .setCheck("String")
        .setAlign(Blockly.ALIGN_CENTRE);
	this.setPreviousStatement(true);
	  this.setInputsInline(false);
    this.setNextStatement(true);
    
	}
};
Blockly.JavaScript['prop_serial_print'] = function(block) {
  // Print statement.
  
  var argument0 = Blockly.JavaScript.valueToCode(block, 'TEXT',
      Blockly.JavaScript.ORDER_NONE) || '\'\'';
	var res = argument0.replace(/'/g, '"');
  return 'print('+res+');\n';
};



Blockly.Blocks['prop_digital_high'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(290);
	   var BOOLEANS =
        [['P0', '0'],
         ['P1', '1'],
		 ['P2', '2'],
		 ['P3', '3'],
		 ['P4', '4'],
		 ['P5', '5'],
		 ['P6', '6'],
		 ['P7', '7'],
		 ['P8', '8'],
		 ['P9', '9'],
		 ['P10', '10'],
		 ['P11', '11'],
		 ['P12', '12'],
		 ['P13', '13'],
		 ['P14', '14'],
		 ['P15', '15']];
    this.appendDummyInput("pin_list")
		.appendField("high")
        .appendField(new Blockly.FieldDropdown(BOOLEANS), "pin_list");
    this.setTooltip('');
	this.setPreviousStatement(true);
	this.setNextStatement(true);
  }
};


Blockly.JavaScript['prop_digital_high'] = function(block) {
  // Boolean values true and false.
  var code = (block.getFieldValue('pin_list'));
  return 'high('+code+');\n';
};

Blockly.Blocks['prop_digital_low'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(290);
	   var BOOLEANS =
        [['P0', '0'],
         ['P1', '1'],
		 ['P2', '2'],
		 ['P3', '3'],
		 ['P4', '4'],
		 ['P5', '5'],
		 ['P6', '6'],
		 ['P7', '7'],
		 ['P8', '8'],
		 ['P9', '9'],
		 ['P10', '10'],
		 ['P11', '11'],
		 ['P12', '12'],
		 ['P13', '13'],
		 ['P14', '14'],
		 ['P15', '15']];
    this.appendDummyInput("pin_list")
		.appendField("low")
        .appendField(new Blockly.FieldDropdown(BOOLEANS), "pin_list");
    this.setTooltip('');
	this.setPreviousStatement(true);
	this.setNextStatement(true);
  }
};


Blockly.JavaScript['prop_digital_low'] = function(block) {
  // Boolean values true and false.
  var code = (block.getFieldValue('pin_list'));
  return 'low('+code+');\n';
};


Blockly.Blocks['brickpi_pause'] = {
  /**
   * Block for numeric value.
   * @this Blockly.Block
   */
  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
	//this.appendField('delay');
    this.appendDummyInput()
		.appendField("pause")
        .appendField(new Blockly.FieldTextInput('0',
        Blockly.FieldTextInput.numberValidator), 'NUM');
  	this.setPreviousStatement(true);
	this.setNextStatement(true);
	this.setTooltip('');
    
  }
};

Blockly.JavaScript['brickpi_pause'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'usleep('+code+'000000);\n';
};


Blockly.Blocks['brickpi_go_forward'] = {
  /**
   * Block for numeric value.
   * @this Blockly.Block
   */
  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	//this.appendField('delay');
    this.appendDummyInput()
		.appendField("Go forward")
		.appendField(new Blockly.FieldTextInput('0',
        Blockly.FieldTextInput.numberValidator), 'NUM');
  	this.setPreviousStatement(true);
	this.setNextStatement(true);
	this.setTooltip('Make the robot go forward for one block');
  }
};

Blockly.JavaScript['brickpi_go_forward'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'go_forward('+code+');\n';
};

Blockly.Blocks['brickpi_go_back'] = {
  /**
   * Block for numeric value.
   * @this Blockly.Block
   */
  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(65);
	//this.appendField('delay');
    this.appendDummyInput()
		.appendField("Go backwards")
		.appendField(new Blockly.FieldTextInput('0',
        Blockly.FieldTextInput.numberValidator), 'NUM');
  	this.setPreviousStatement(true);
	this.setNextStatement(true);
	this.setTooltip('Make the robot go back for one block');
    
  }
};

Blockly.JavaScript['brickpi_go_back'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'go_back('+code+');\n';
};

Blockly.Blocks['brickpi_go_right'] = {
  /**
   * Block for numeric value.
   * @this Blockly.Block
   */
  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(120);
	//this.appendField('delay');
    this.appendDummyInput()
		.appendField("Turn right")
		.appendField(new Blockly.FieldTextInput('0',
        Blockly.FieldTextInput.numberValidator), 'NUM');
  	this.setPreviousStatement(true);
	this.setNextStatement(true);
	this.setTooltip('Make the robot turn right');
  }
};

Blockly.JavaScript['brickpi_go_right'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'go_right('+code+');\n';
};

Blockly.Blocks['brickpi_go_left'] = {
  /**
   * Block for numeric value.
   * @this Blockly.Block
   */
  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(290);
	//this.appendField('delay');
    this.appendDummyInput()
		.appendField("Turn left")
		.appendField(new Blockly.FieldTextInput('0',
        Blockly.FieldTextInput.numberValidator), 'NUM');
  	this.setPreviousStatement(true);
	this.setNextStatement(true);
	this.setTooltip('Make the robot turn left');
  }
};

Blockly.JavaScript['brickpi_go_left'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'go_left('+code+');\n';
};

Blockly.Blocks['brickpi_turn_around'] = {
  /**
   * Block for numeric value.
   * @this Blockly.Block
   */
  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Turn around");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Make the robot make a 180 degree turn.');
    
  }
};

Blockly.JavaScript['brickpi_turn_around'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'turn_around();\n';
};

Blockly.Blocks['brickpi_for_loop'] = {
  init: function() {
    this.setColour(120);
    this.appendDummyInput()
        .appendTitle('Repeat')
        .appendTitle(new Blockly.FieldTextInput('10',
            Blockly.FieldTextInput.nonnegativeIntegerValidator), 'TIMES')
        .appendTitle('Times');
    this.appendStatementInput('DO')
        .appendTitle(Blockly.LANG_CONTROLS_REPEAT_INPUT_DO);
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setTooltip('For loop');
  }
};



Blockly.JavaScript['brickpi_for_loop'] = function() {
  // Repeat n times (internal number).
  var repeats = Number(this.getTitleValue('TIMES'));
  var branch = Blockly.JavaScript.statementToCode(this, 'DO');
  if (Blockly.JavaScript.INFINITE_LOOP_TRAP) {
    branch = Blockly.JavaScript.INFINITE_LOOP_TRAP.replace(/%1/g,
        '\'' + this.id + '\'') + branch;
  }
  var loopVar = Blockly.JavaScript.variableDB_.getDistinctName(
      'count', Blockly.Variables.NAME_TYPE);
  var code = 'for (' + loopVar + ' = 0; ' +
      loopVar + ' < ' + repeats + '; ' +
      loopVar + '++) {\n' +
      branch + '}\n';
  return code;
};
