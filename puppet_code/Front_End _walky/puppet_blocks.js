Blockly.Blocks['puppet_say_hello'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Say_Hello");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Say Hello');
    
  }
};

Blockly.JavaScript['puppet_say_hello'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Say_Hello();\n';
};

Blockly.Blocks['puppet_jump'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Jump");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Jump');
    
  }
};

Blockly.JavaScript['puppet_jump'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Jump();\n';
};





Blockly.Blocks['puppet_dance'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Dance");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Dance');
    
  }
};

Blockly.JavaScript['puppet_dance'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Dance();\n';
};



Blockly.Blocks['puppet_take_a_pic'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Take a Pic");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Take a Pic');
    
  }
};

Blockly.JavaScript['puppet_take_a_pic'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Take_a_Pic();\n';
};


Blockly.Blocks['puppet_green_gblin'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Green Goblin");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Green Goblin');

    
  }
};

Blockly.JavaScript['puppet_green_gblin'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Green_Goblin();\n';
};

Blockly.Blocks['puppet_costume'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("See my costume");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('See my costume');

    
  }
};

Blockly.JavaScript['puppet_costume'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'See_my_Costume();\n';
};




Blockly.Blocks['puppet_walk'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Walk");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Walk');

    
  }
};

Blockly.JavaScript['puppet_walk'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Walk();\n';
};


Blockly.Blocks['puppet_say_bye'] = {

  init: function() {
     this.setHelpUrl('http://www.example.com/');
    this.setColour(230);
  //this.appendField('delay');
    this.appendDummyInput()
    .appendField("Say Bye");
    this.setPreviousStatement(true);
  this.setNextStatement(true);
  this.setTooltip('Say Bye!');

    
  }
};

Blockly.JavaScript['puppet_say_bye'] = function(block) {
  // Numeric value.
  var code = parseFloat(block.getFieldValue('NUM'));
  return 'Say_Bye();\n';
};














